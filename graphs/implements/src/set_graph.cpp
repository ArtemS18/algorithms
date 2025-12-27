#include "set_graph.h"
#include <assert.h>

SetGraph::SetGraph(int size){
    binTrees.resize(size);
}

SetGraph::SetGraph(const IGraph &graph){
    binTrees.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); ++i)
    {
        for (int to : graph.GetNextVertices(i)) { 
            binTrees[i].insert(to);
        }
    }
}

SetGraph::~SetGraph(){

}

void SetGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < binTrees.size());
    assert(0 <= to && to < binTrees.size());
    binTrees[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return binTrees.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < binTrees.size());
    std::vector<int> vertices;
    for (int to : binTrees[vertex]){
        vertices.push_back(to);
    }
    return vertices;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < binTrees.size());

   std::vector<int> prevVertices;
    
    for (int from = 0; from < binTrees.size(); ++from)
    {
        if (binTrees[from].count(vertex) != 0)
            prevVertices.push_back(from);
    }
    return prevVertices;

}