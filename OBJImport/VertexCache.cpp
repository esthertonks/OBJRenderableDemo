#include "stdafx.h"
#include "VertexCache.h"
#include "Vertex.h"


VertexCache::VertexCache()
{
}


VertexCache::~VertexCache()
{
}

int VertexCache::GetDuplicateVertexIndex(const int positionIndex, const Vertex &vertex, const std::shared_ptr<std::vector<Vertex>> vertexBuffer) {
	auto iter = m_vertexIndexCache.find(positionIndex);
	while (iter != m_vertexIndexCache.end()) {
		if (vertex == vertexBuffer->at(iter->second)) {
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
