#pragma once
class Vector3
{
public:
	Vector3() {
		Vector3(0.0f, 0.0f, 0.0f);
	}

	Vector3(float x, float y, float z) 
		: m_x(x), m_y(y), m_z(z)
	{
	}

	~Vector3() {};

	inline bool operator == (const Vector3 &vector3) const {
		return ((abs(vector3.m_x - this->m_x) < 0.0001) && (abs(vector3.m_y - this->m_y) < 0.0001) && (abs(vector3.m_z - this->m_z) < 0.0001));
	}

	inline float DotProduct(Vector3 &vector) {
		return m_x * vector.m_x + m_y * vector.m_y + m_z * vector.m_z;
	}

	void CrossProduct(Vector3 &vector1, Vector3 &vector2) {
		m_x = vector1.m_y * vector2.m_z - vector1.m_z * vector2.m_y;
		m_y = vector1.m_z * vector2.m_x - vector1.m_x * vector2.m_z;
		m_z = vector1.m_x * vector2.m_y - vector1.m_y * vector2.m_x;

		return;
	}

	inline float Length() {
		return (float)sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
	}

	void CalculateNormal(Vector3 &v1, Vector3 &v2, Vector3 &v3) {
		Vector3 a;
		Vector3 b;

		a.m_x = v2.m_x - v1.m_x;
		a.m_y = v2.m_y - v1.m_y;
		a.m_z = v2.m_z - v1.m_z;

		b.m_x = v3.m_x - v2.m_x;
		b.m_y = v3.m_y - v2.m_y;
		b.m_z = v3.m_z - v2.m_z;

		CrossProduct(a, b);
	}

	bool Normalise() {
		float length = Length();

		if (length != 0) {
			length = 1.0f / length;
			m_x *= length;
			m_y *= length;
			m_z *= length;

			return true;
		}

		return false;
	}

	float m_x;
	float m_y;
	float m_z;
};

