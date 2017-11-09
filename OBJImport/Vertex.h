#pragma once

#include "Vector3.h"
#include "Vector2.h"

class Vertex
{
public:

	Vertex() {  
	}

	Vertex(Vector3 position, Vector3 normal, Vector2 texCoord) {
		this->m_position = position;
		this->m_normal = normal;
		this->m_texCoord = texCoord;
	}

	inline bool operator == (const Vertex &vertex) const {
		return m_texCoord == vertex.m_texCoord &&
			m_normal == vertex.m_normal &&
			m_position == vertex.m_position;
	}

	inline bool operator == (Vertex &vertex) const {
			return m_texCoord == vertex.m_texCoord &&
				m_normal == vertex.m_normal &&
				m_position == vertex.m_position;
	}

	Vector3 m_position;
	Vector3 m_normal;
	Vector2 m_texCoord;

};

