#include <assert.h>
#include <queue>
#include <iostream>
#include <set>
#include <vector>

struct IGraph {
    virtual ~IGraph() {}
        
    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const  = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};


struct SetGraph: public IGraph
{
public:
    SetGraph(int size){
        adj.resize(size);
    }
    
    ~SetGraph(){

    }
    
    void AddEdge(int from, int to) {
        assert(0 <= from && from < adj.size());
        assert(0 <= to && to < adj.size());
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    int VerticesCount() const {
        return adj.size();
    }
    std::vector<int> GetNextVertices(int vertex) const {
        assert(0 <= vertex && vertex < adj.size());
        return adj[vertex];
    }
    
    std::vector<int> GetPrevVertices(int vertex) const {
        assert(0 <= vertex && vertex < adj.size());
        return adj[vertex];

    }

private:
    std::vector<std::vector<int>> adj;
};

int findPath(const IGraph &graph, int from, int to){
    std::vector<int> pathDist(graph.VerticesCount(), -1);
    std::vector<int> pathCount(graph.VerticesCount(), 0);
    std::queue<int> q;

    pathCount[from] = 1;
    pathDist[from] = 0;
    q.push(from);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto nextV: graph.GetNextVertices(v))
        {
            if (pathDist[nextV] == -1)
            {
                pathDist[nextV] = pathDist[v]+1;
                pathCount[nextV] = pathCount[v];
                q.push(nextV);
            }
            else if (pathDist[nextV] == pathDist[v] + 1){
                pathCount[nextV] += pathCount[v];

            }
        }
    }
    return (pathDist[to] == -1) ? 0 : (int)pathCount[to];
}



int main() {
    int v, n;
    std::cin >> v; 
    std::cin >> n; 

    SetGraph graph(v);

    for (int i = 0; i < n; ++i) {
        int from, to;
        std::cin >> from >> to;
        graph.AddEdge(from, to);
    }

    int u, w;
    std::cin >> u >> w;

    std::cout << findPath(graph, u, w) << std::endl;

    return 0;
}