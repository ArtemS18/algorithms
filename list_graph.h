#include "igraph.h"
#include <vector>

struct ListGraph: public IGraph
{
public:
    ListGraph(int size);
    
    ListGraph(const IGraph &graph);
    
    ~ListGraph();
    
    void AddEdge(int from, int to);
    
    int VerticesCount() const;
    std::vector<int> GetNextVertices(int vertex) const;
    
    std::vector<int> GetPrevVertices(int vertex) const;

private:
    std::vector<std::vector<int>> adjacencyLists;
};