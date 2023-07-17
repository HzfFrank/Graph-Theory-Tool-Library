#ifndef UNDIRECTEDWEIGHTEDGRAPH_H
#define UNDIRECTEDWEIGHTEDGRAPH_H
#include "WeightedGraph.h"
#include "UndirectedGraph.h"

template <typename T>
class UndirectedWeightedGraph : public WeightedGraph<T>{
public:
    UndirectedWeightedGraph() : WeightedGraph<T>() {};
    ~UndirectedWeightedGraph() {};
    typedef T TValue;
public:
    bool AddEdge(int vertex1, int vertex2, T weight) {
        if (vertex1 != vertex2)
        {
            if (WeightedGraph<T>::AddEdge(vertex1, vertex2, weight) && WeightedGraph<T>::AddEdge(vertex2, vertex1, weight))
                return true;
            return false;
        }
        else
        {
            return WeightedGraph<T>::AddEdge(vertex1, vertex2, weight);
        }
    }

    bool RemoveEdge(int vertex1, int vertex2) {
        if (vertex1 != vertex2)
        {
            if (WeightedGraph<T>::RemoveEdge(vertex1, vertex2) && WeightedGraph<T>::RemoveEdge(vertex2, vertex1))
                return true;
        }
        else
        {
            if (WeightedGraph<T>::RemoveEdge(vertex1, vertex2))
                return true;
        }
        return false;
    }

    int CountEdges() const {
        return UndirectedWeightedGraph<T>::GetEdges().size();
    }

    std::vector<Edge> GetEdges() const {
        std::vector<Edge> tmp = WeightedGraph<T>::GetEdges();
        std::vector<Edge> ans;
        for (auto it = tmp.begin(); it != tmp.end(); it++) {
            bool flag = true;
            for (auto s = ans.begin(); s != ans.end(); s++)
            {
                if (s->GetSource() == it->GetDestination() && s->GetDestination() == it->GetSource())
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                Edge e(it->GetSource(), it->GetDestination());
                ans.push_back(e);
            }
        }
        return ans;
    }

    int GetDegree(int vertex) const {
        int ans = 0;
        std::vector<Edge> tmp = Graph::GetEdges();
        for (auto it = tmp.begin(); it != tmp.end(); it++) {
            if (it->GetSource() == vertex)
            {
                if (it->GetSource() == it->GetDestination())
                    ans += 2;
                else
                    ans++;
            }
        }
        return ans;
    }
};

#endif
