#pragma once
class Vector2
{
public:
	Vector2()
	{
		Vector2(0.0f, 0.0f);
	}

	Vector2(float x, float y)
		: m_x(x), m_y(y)
	{
	}

	~Vector2() {};

	inline bool operator == (const Vector2 &vector2) const {
		return this->m_x == vector2.m_x &&
			this->m_y == vector2.m_y;
	}

	float m_x;
	float m_y;
};

