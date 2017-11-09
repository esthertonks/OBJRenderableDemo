#pragma once

enum class PrimitiveType
{
	Triangle,
	Quad
};

class PrimitiveCommand
{
public:

	PrimitiveCommand()
	{
		m_offset = 3;
		m_type = PrimitiveType::Triangle;
	}

	PrimitiveCommand(int offset, PrimitiveType type)
	{
		m_offset = offset;
		m_type = type;
	}

	~PrimitiveCommand() {};

	inline void SetOffset(int offset)
	{
		m_offset = offset;
	}

	inline int GetOffset()
	{
		return m_offset;
	}

	inline void SetType(PrimitiveType type)
	{
		m_type = type;
	}

	inline PrimitiveType GetType()
	{
		return m_type;
	}

private:
	int m_offset;
	PrimitiveType m_type;
};

