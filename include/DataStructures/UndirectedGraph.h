#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include <DataStructures/Graph.h>

class UndirectedGraph : public Graph {
 private:
    int cnt;
 public:
    UndirectedGraph();
    ~UndirectedGraph() {};
 public:
    bool AddEdge(int vertex1, int vertex2);
    bool RemoveEdge(int vertex1, int vertex2);
    int CountEdges() const;
    std::vector<Edge> GetEdges() const;
    int GetDegree(int vertex) const;
};

#endif