#include "igraph.h"
#include <vector>
#include <set>

struct SetGraph: public IGraph
{
public:
    SetGraph(int size);
    
    SetGraph(const IGraph &graph);
    
    ~SetGraph();
    
    void AddEdge(int from, int to);
    
    int VerticesCount() const;
    std::vector<int> GetNextVertices(int vertex) const;
    
    std::vector<int> GetPrevVertices(int vertex) const;

private:
    std::vector<std::set<int>> binTrees;
};