#pragma once
class Vector3
{
public:
	Vector3() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vector3(float x, float y) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	~Vector3() {};

	inline bool operator == (const Vector3& vector3) const {
		return this->x == vector3.x &&
			this->y == vector3.y &&
			this->z == vector3.z;
	}

	float x;
	float y;
	float z;
};

