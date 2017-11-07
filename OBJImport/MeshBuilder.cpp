#include "stdafx.h"
#include "MeshBuilder.h"
#include "Vertex.h"
#include "Mesh.h"
#include "PrimitiveCommand.h"

MeshBuilder::MeshBuilder()
{
	positionList = std::unique_ptr<std::vector<Vector3>>(new std::vector<Vector3>());
	normalList = std::unique_ptr<std::vector<Vector3>>(new std::vector<Vector3>());
	texCoordList = std::unique_ptr<std::vector<Vector2>>(new std::vector<Vector2>());
}

bool MeshBuilder::AddVertexPosition(const Vector3 &position)
{
	positionList->emplace_back(position);

	return true;
}

bool MeshBuilder::AddVertexNormal(const Vector3 &normal)
{
	normalList->emplace_back(normal);

	return true;
}

bool MeshBuilder::AddVertexTextureCoords(const Vector2 &texCoords)
{
	texCoordList->emplace_back(texCoords);

	return true;
}

bool MeshBuilder::AddTriangle(const int positionIndices[3], const int normalIndices[3], const int texCoordIndices[3])
{
	int offset = -1;

	for (int triangleCorner = 0; triangleCorner < 3; triangleCorner++) {
		Vertex vertex;

		vertex.position = positionList->at(positionIndices[triangleCorner]);
		vertex.normal = normalList->at(normalIndices[triangleCorner]);
		vertex.texCoord = texCoordList->at(texCoordIndices[triangleCorner]);

		int index = m_mesh->AddVertex(vertex);
		m_mesh->AddIndex(index);

		if (triangleCorner == 0) {
			offset = index;
		}
	}

	assert(offset != -1);

	PrimitiveType type = PrimitiveType::TRIANGLE;
	PrimitiveCommand primitiveCommand(offset, type);

	return true;
}

bool MeshBuilder::AddQuad(const int positionIndices[4], const int normalIndices[4], const int texCoordIndices[4])
{
	int offset = -1;

	for (int triangleCorner = 0; triangleCorner < 4; triangleCorner++) {
		Vertex vertex;

		vertex.position = positionList->at(positionIndices[triangleCorner]);
		vertex.normal = normalList->at(normalIndices[triangleCorner]);
		vertex.texCoord = texCoordList->at(texCoordIndices[triangleCorner]);

		int index = m_mesh->AddVertex(vertex);
		m_mesh->AddIndex(index);

		if (triangleCorner == 0) {
			offset = index;
		}
	}

	assert(offset != -1);

	PrimitiveType type = PrimitiveType::QUAD;
	PrimitiveCommand primitiveCommand(offset, type);

	return true;
}



