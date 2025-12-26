#include "matrix_graph.h"
#include <assert.h>

MatrixGraph::MatrixGraph(int size){
    matrix.resize(size);
    for (int i = 0; i < size; ++i)
    {
        matrix[i].resize(size, false);
    }
}

MatrixGraph::MatrixGraph(const IGraph &graph){
    matrix.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); ++i)
    {
        for (int to : graph.GetNextVertices(i)) { 
            matrix[i].resize(graph.VerticesCount(), false);
            matrix[i][to] = true;
        }
    }
}

MatrixGraph::~MatrixGraph(){

}

void MatrixGraph::AddEdge(int from, int to)  {
    assert(0 <= from && from < matrix.size());
    assert(0 <= to && to < matrix.size());
    matrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const{
    return matrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < matrix.size());
    std::vector<int> vertices;
    for (int i =0; i < matrix[vertex].size(); ++i){
        if (matrix[vertex][i])
            vertices.push_back(i);
    }
    return vertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < matrix.size());

    std::vector<int> vertices;
    for (int i =0; i < matrix.size(); ++i){
        if (matrix[i][vertex])
            vertices.push_back(i);
    }
    return vertices;

}