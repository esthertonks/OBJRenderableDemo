#pragma once

class Vertex;

class VertexCache
{
public:
	VertexCache();
	~VertexCache();

	void AddIndexToCache(const int oldIndex, const int newIndex);
	int GetDuplicateVertexIndex(const int positionIndex, const Vertex &vertex, const std::shared_ptr<std::vector<Vertex>> vertexBuffer);

private:

	std::multimap<int, int> m_vertexIndexCache;
};

