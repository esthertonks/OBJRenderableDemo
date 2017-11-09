#include "stdafx.h"
#include "VertexCache.h"
#include "Vertex.h"


VertexCache::VertexCache()
{
}


VertexCache::~VertexCache()
{
}

int VertexCache::GetDuplicateVertexIndex(const int positionIndex, const Vertex &vertex, const std::vector<Vertex> &vertexBuffer) {
	if (m_vertexIndexCache.size() == 0) {
		return -1;
	}

	auto iter = m_vertexIndexCache.find(positionIndex);
	while (iter != m_vertexIndexCache.end()) {
		if (vertex == vertexBuffer.at(iter->second)) {
			return iter->second;
		}
		++iter;
	}

	return -1;
}

void VertexCache::AddIndexToCache(const int oldIndex, const int newIndex)
{
	m_vertexIndexCache.emplace(oldIndex, newIndex);
}
