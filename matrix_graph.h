#include "igraph.h"
#include <vector>

struct MatrixGraph: public IGraph
{
public:
    MatrixGraph(int size);
    
    MatrixGraph(const IGraph &graph);
    
    ~MatrixGraph();
    
    void AddEdge(int from, int to);
    
    int VerticesCount() const;
    std::vector<int> GetNextVertices(int vertex) const;
    
    std::vector<int> GetPrevVertices(int vertex) const;

private:
    std::vector<std::vector<bool>> matrix;
};