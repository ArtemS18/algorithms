#include "igraph.h"
#include <vector>

struct ArcGraph: public IGraph
{
public:
    ArcGraph(int size);
    
    ArcGraph(const IGraph &graph);
    
    ~ArcGraph();
    
    void AddEdge(int from, int to);
    
    int VerticesCount() const;
    std::vector<int> GetNextVertices(int vertex) const;
    
    std::vector<int> GetPrevVertices(int vertex) const;

private:
    std::vector<std::pair<int, int>> edgeVector;
    int verticesCount;
};