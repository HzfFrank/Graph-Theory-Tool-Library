#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include "Graph.h"
#include "WeightedEdge.h"

template <typename T>
class WeightedGraph : public Graph {
private:
    std::map<std::pair<int, int>, T> G;
public:
    WeightedGraph() : Graph() {};
    ~WeightedGraph() {};
    typedef T TValue;
public:
    bool AddEdge(int vertex1, int vertex2, T weight) {
        bool status = Graph::AddEdge(vertex1, vertex2);
        if (status == false) return status;
        G[std::make_pair(vertex1, vertex2)] = weight;
        return true;
    }

    T GetWeight(int vertex1, int vertex2) const {
        if (ContainsEdge(vertex1, vertex2)) return G.at(std::make_pair(vertex1, vertex2));
        return 0;
    }

    std::vector<WeightedEdge<T>> GetIncomingEdges(int vertex) const {
        std::vector<Edge> t = Graph::GetIncomingEdges(vertex);
        std::vector<WeightedEdge<T>> ans;
        for (auto tmp : t)
        {
            WeightedEdge e(tmp.GetSource(), tmp.GetDestination(), GetWeight(tmp.GetSource(), tmp.GetDestination()));
            ans.push_back(e);
        }
        return ans;
    }

    std::vector<WeightedEdge<T>> GetOutgoingEdges(int vertex) const {
        std::vector<Edge> t = Graph::GetOutgoingEdges(vertex);
        std::vector<WeightedEdge<T>> ans;
        for (auto tmp : t)
        {
            WeightedEdge e(tmp.GetSource(), tmp.GetDestination(), GetWeight(tmp.GetSource(), tmp.GetDestination()));
            ans.push_back(e);
        }
        return ans;
    }
};

#endif
