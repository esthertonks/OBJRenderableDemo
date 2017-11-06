#pragma once
class Vertex
{
public:

	Vertex() { 
		vector4[0] = 0.0f;
		vector4[1] = 0.0f; 
		vector4[2] = 0.0f; 
		vector4[3] = 0.0f; 
	}

	Vertex(float x, float y, float z, float w) {
		vector4[0] = x;
		vector4[1] = y;
		vector4[2] = z;
		vector4[3] = w;
	}

	inline bool operator == (const Vertex& vertex) const {
		return vector4[0] == vertex.vector4[0] &&
			vector4[1] == vertex.vector4[1] &&
			vector4[2] == vertex.vector4[2] &&
			vector4[3] == vertex.vector4[3];
	}

	float vector4[4];

};

