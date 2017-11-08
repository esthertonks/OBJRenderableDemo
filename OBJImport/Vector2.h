#pragma once
class Vector2
{
public:
	Vector2() {
		x = 0.0f;
		y = 0.0f;
	}

	Vector2(float x, float y) {
		this->x = x;
		this->y = y;
	}

	~Vector2() {};

	inline bool operator == (const Vector2& vector2) const {
		return this->x == vector2.x &&
			this->y == vector2.y;
	}

	float x;
	float y;
};

