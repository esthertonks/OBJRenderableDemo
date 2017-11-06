#pragma once

enum PrimitiveType
{
	TRIANGLE = 3,
	QUAD = 4
};

class PrimitiveCommandList
{
public:
	PrimitiveCommandList();
	~PrimitiveCommandList();

private:
	int offset;
	int type;
};

