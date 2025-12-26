#include "arc_graph.h"
#include <assert.h>

ArcGraph::ArcGraph(int size){
    verticesCount = size;
}

ArcGraph::ArcGraph(const IGraph &graph){
    verticesCount = graph.VerticesCount();
    for (int from = 0; from < verticesCount; ++from)
    {
        for (int to : graph.GetNextVertices(from)) { 
            edgeVector.push_back(std::pair(from, to));
        }
    }
}

ArcGraph::~ArcGraph(){

}

void ArcGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < edgeVector.size());
    assert(0 <= to && to < edgeVector.size());
    edgeVector.push_back(std::pair(from, to));
}

int ArcGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < edgeVector.size());
    std::vector<int> vertices;
    for (auto edge : edgeVector)
    {
        if (edge.first == vertex){
            vertices.push_back(edge.second);
        }
    }
    return vertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < edgeVector.size());

    std::vector<int> vertices;
    for (auto edge : edgeVector)
    {
        if (edge.second == vertex){
            vertices.push_back(edge.first);
        }
    }
    return vertices;

}