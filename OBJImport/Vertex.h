#pragma once

#include "Vector3.h"
#include "Vector2.h"

class Vertex
{
public:

	Vertex() {  
	}

	Vertex(Vector3 position, Vector3 normal, Vector2 texCoord) {
		this->position = position;
		this->normal = normal;
		this->texCoord = texCoord;
	}

	inline bool operator == (const Vertex& vertex) const {
		return texCoord == vertex.texCoord &&
			normal == vertex.normal &&
			position == vertex.position;
	}

	inline bool operator == (Vertex& vertex) const {
			return texCoord == vertex.texCoord &&
				normal == vertex.normal &&
				position == vertex.position;
	}

	Vector3 position;
	Vector3 normal;
	Vector2 texCoord;

};

