#include "stdafx.h"
#include "MeshBuilder.h"
#include "Mesh.h"
#include "PrimitiveCommand.h"
#include "VertexCache.h"

MeshBuilder::MeshBuilder() : m_mesh(std::shared_ptr<Mesh>(new Mesh)),
					m_positionList(std::unique_ptr<std::vector<Vector3>>(new std::vector<Vector3>())),
					m_normalList(std::unique_ptr<std::vector<Vector3>>(new std::vector<Vector3>())),
					m_texCoordList(std::unique_ptr<std::vector<Vector2>>(new std::vector<Vector2>())),
					m_vertexCache(std::unique_ptr<VertexCache>(new VertexCache()))
{

}

bool MeshBuilder::AddVertexPosition(const Vector3 &position)
{
	m_positionList->emplace_back(position);

	return true;
}

bool MeshBuilder::AddVertexNormal(const Vector3 &normal)
{
	m_normalList->emplace_back(normal);

	return true;
}

bool MeshBuilder::AddVertexTextureCoords(const Vector2 &texCoords)
{
	m_texCoordList->emplace_back(texCoords);

	return true;
}

// TODO can we undubplicate this?
bool MeshBuilder::AddTriangle(const std::array<int, 3 > positionIndices, const std::array<int, 3>texCoordIndices, const std::array<int, 3> normalIndices)
{
	auto indexOffset = m_mesh->GetCurrentIndexBufferIndex();
	// TODO do we need to reomve duplicate verts?
	for (int triangleCorner = 0; triangleCorner < 3; triangleCorner++) {
		Vertex vertex;
		auto positionIndex = positionIndices[triangleCorner];

		assert(m_positionList->size() > positionIndex);
		vertex.position = m_positionList->at(positionIndex);
		if (m_texCoordList->size() > 0) {
			vertex.texCoord = m_texCoordList->at(texCoordIndices[triangleCorner]);
		}
		if (m_normalList->size() > 0) {
			vertex.normal = m_normalList->at(normalIndices[triangleCorner]);
		}

		auto vertexIndex = m_vertexCache->GetDuplicateVertexIndex(positionIndex, vertex, m_mesh->GetVertexBuffer());
		if (vertexIndex != -1) { // We found an idenical vertex in the vertexbuffer just add the index
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

	auto type = PrimitiveType::TRIANGLE;
	PrimitiveCommand primitiveCommand(indexOffset, type);
	m_mesh->AddPrimitive(primitiveCommand);

	return true;
}

bool MeshBuilder::AddQuad(const std::array<int, 4>positionIndices, const std::array<int, 4> texCoordIndices, const std::array<int, 4> normalIndices)
{
	auto indexOffset = m_mesh->GetCurrentIndexBufferIndex();

	for (int triangleCorner = 0; triangleCorner < 4; triangleCorner++) {
		Vertex vertex;

		auto positionIndex = positionIndices[triangleCorner];

		assert(m_positionList->size() > positionIndex);
		vertex.position = m_positionList->at(positionIndex);

		if (m_texCoordList->size() > 0) {
			vertex.texCoord = m_texCoordList->at(texCoordIndices[triangleCorner]);
		}

		if (m_normalList->size() > 0) {
			vertex.normal = m_normalList->at(normalIndices[triangleCorner]);
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

	auto type = PrimitiveType::QUAD;
	PrimitiveCommand primitiveCommand(indexOffset, type);
	m_mesh->AddPrimitive(primitiveCommand);

	return true;
}

std::shared_ptr<Mesh> MeshBuilder::GetCompleteMesh()
{
	// Generate normals if we didnt load them.
	if (m_normalList->empty()) {
		GenerateNormals();
	}

	// TODO probably need to generate default material to render

	return m_mesh;
}

void MeshBuilder::GenerateNormals() {
	// TODO
}



