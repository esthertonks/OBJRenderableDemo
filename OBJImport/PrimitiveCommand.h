#pragma once

enum PrimitiveType
{
	TRIANGLE = 3,
	QUAD = 4
};

class PrimitiveCommand
{
public:
	PrimitiveCommand(int offset, PrimitiveType type)
	{
		m_offset = offset;
		m_type = type;
	}

	~PrimitiveCommand() {};

	void SetOffset(int offset)
	{
		m_offset = offset;
	}

	void SetType(PrimitiveType type)
	{
		m_type = type;
	}

private:
	int m_offset;
	PrimitiveType m_type;
};

