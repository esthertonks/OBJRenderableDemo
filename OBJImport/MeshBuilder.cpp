#include "stdafx.h"
#include "MeshBuilder.h"
#include "Mesh.h"
#include "PrimitiveCommand.h"
#include "VertexCache.h"

MeshBuilder::MeshBuilder() : m_mesh(std::shared_ptr<Mesh>(std::make_shared<Mesh>())),
					m_vertexCache(std::unique_ptr<VertexCache>(std::make_unique<VertexCache>()))
{

}

bool MeshBuilder::AddVertexPosition(const Vector3 &position)
{
	m_positionList.emplace_back(position);

	return true;
}

bool MeshBuilder::AddVertexNormal(const Vector3 &normal)
{
	m_normalList.emplace_back(normal);

	return true;
}

bool MeshBuilder::AddVertexTextureCoords(const Vector2 &texCoords)
{
	m_texCoordList.emplace_back(texCoords);

	return true;
}

// TODO can we deduplicate this?
bool MeshBuilder::AddTriangle(const std::array<int, 3 > positionIndices, const std::array<int, 3>texCoordIndices, const std::array<int, 3> normalIndices)
{
	auto indexOffset = m_mesh->GetCurrentIndexBufferIndex();

	Vector3 normal;
	if (m_normalList.size() == 0) {
		normal = CalculateTriangleNormal(positionIndices);
	}

	for (int triangleCorner = 0; triangleCorner < 3; triangleCorner++) {
		Vertex vertex;
		auto positionIndex = positionIndices[triangleCorner];

		assert(m_positionList.size() > positionIndex);
		vertex.m_position = m_positionList.at(positionIndex);
		if (m_texCoordList.size() > 0) {
			vertex.m_texCoord = m_texCoordList.at(texCoordIndices[triangleCorner]);
		}
		if (m_normalList.size() > 0) {
			vertex.m_normal = m_normalList.at(normalIndices[triangleCorner]);
		}
		else {
			vertex.m_normal = normal;
		}

		auto vertexIndex = m_vertexCache->GetDuplicateVertexIndex(positionIndex, vertex, m_mesh->GetVertexBuffer());
		if (vertexIndex != -1) { // We found an identical vertex in the vertexbuffer just add the index
			m_mesh->AddIndex(vertexIndex);
		}
		else { // Add the vertex and add an new index
			m_mesh->AddVertex(vertex);
			vertexIndex = m_mesh->GetCurrentVertexIndex();
			m_mesh->AddIndex(vertexIndex);
			// Add the current vertex to the cache with the original position as key.
			m_vertexCache->AddIndexToCache(positionIndex, vertexIndex);
		}
	}

	auto type = PrimitiveType::Triangle;
	PrimitiveCommand primitiveCommand(indexOffset, type);
	m_mesh->AddPrimitive(primitiveCommand);

	return true;
}

bool MeshBuilder::AddQuad(const std::array<int, 4>positionIndices, const std::array<int, 4> texCoordIndices, const std::array<int, 4> normalIndices)
{
	auto indexOffset = m_mesh->GetCurrentIndexBufferIndex();

	Vector3 normal;
	if (m_normalList.size() == 0) {
		normal = CalculateQuadNormal(positionIndices);
	}

	for (int triangleCorner = 0; triangleCorner < 4; triangleCorner++) {
		Vertex vertex;

		auto positionIndex = positionIndices[triangleCorner];

		assert(m_positionList.size() > positionIndex);
		vertex.m_position = m_positionList.at(positionIndex);

		if (m_texCoordList.size() > 0) {
			vertex.m_texCoord = m_texCoordList.at(texCoordIndices[triangleCorner]);
		}

		if (m_normalList.size() > 0) {
			vertex.m_normal = m_normalList.at(normalIndices[triangleCorner]);
		}
		else {
			vertex.m_normal = normal;
		}

		auto vertexIndex = m_vertexCache->GetDuplicateVertexIndex(positionIndex, vertex, m_mesh->GetVertexBuffer());
		if (vertexIndex != -1) { // We found an idenical vertex in the vertexbuffer just add the index
			m_mesh->AddIndex(vertexIndex);
		}
		else {
			m_mesh->AddVertex(vertex);
			vertexIndex = m_mesh->GetCurrentVertexIndex();
			m_mesh->AddIndex(vertexIndex);
			// Add the current vertex to the cache with the original position as key.
			m_vertexCache->AddIndexToCache(positionIndex, vertexIndex);
		}
	}

	auto type = PrimitiveType::Quad;
	PrimitiveCommand primitiveCommand(indexOffset, type);
	m_mesh->AddPrimitive(primitiveCommand);

	return true;
}

Vector3 MeshBuilder::CalculateQuadNormal(const std::array<int, 4>positionIndices) {
	// Just take the first triangle and assume the quad is planar.
	return CalculateNormal(positionIndices[0], positionIndices[1], positionIndices[2]);
}

Vector3 MeshBuilder::CalculateTriangleNormal(const std::array<int, 3>positionIndices) {
	return CalculateNormal(positionIndices[0], positionIndices[1], positionIndices[2]);
}

Vector3 MeshBuilder::CalculateNormal(const int positionIndex1, const int positionIndex2, const int positionIndex3) {
	Vector3 normal;
	// Assume the quad is planar so just take the triangle
	auto vertexPosition1 = m_positionList.at(positionIndex1);
	auto vertexPosition2 = m_positionList.at(positionIndex2);
	auto vertexPosition3 = m_positionList.at(positionIndex3);

	normal.CalculateNormal(vertexPosition1, vertexPosition2, vertexPosition3);
	normal.Normalise();

	return normal;
}

std::shared_ptr<Mesh> MeshBuilder::GetCompleteMesh()
{
	// TODO probably need to generate default material to render

	return m_mesh;
}



