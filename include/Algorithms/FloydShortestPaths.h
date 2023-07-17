#ifndef FLOYDSHORTESTPATHS
#define FLOYDSHORTESTPATHS

#include <Algorithms/MultiSourceShortestPaths.h>
#include <queue>
#include <stack>
#include <DataStructures/WeightedEdge.h>

template<typename TValue>
TValue epsilon_real(std::true_type) {
    return 1e-6;
}

template<typename TValue>
TValue epsilon_real(std::false_type) {
    return TValue();
}

template<typename TValue>
TValue epsilon() {
    return epsilon_real<TValue>(std::is_floating_point<TValue>());
}

template <typename TGraph>
class FloydShortestPaths : public MultiSourceShortestPaths<TGraph> {
public:
    FloydShortestPaths(const TGraph *graph) : MultiSourceShortestPaths<TGraph>(graph) {
        bool flag = false;
        static_assert(std::is_default_constructible<typename TGraph::TValue>::value, "TValue requires default constructor");
        std::vector<int> V = graph->GetVertices();
        for (auto t : V) {
            std::vector<WeightedEdge<typename TGraph::TValue>> E;
            E = graph->GetOutgoingEdges(t);
            for (auto j : E) {
                int e = j.GetDestination();
                typename TGraph::TValue v = j.GetWeight();
                MultiSourceShortestPaths<TGraph>::dis[std::make_pair(t, e)] = v;
            }
            MultiSourceShortestPaths<TGraph>::dis[std::make_pair(t, t)] = epsilon<typename TGraph::TValue>();
        }
        for (auto i : V) {
            for (auto j : V) {
                if (i != j && MultiSourceShortestPaths<TGraph>::dis.find(std::make_pair(i, j)) != MultiSourceShortestPaths<TGraph>::dis.end())
                    MultiSourceShortestPaths<TGraph>::pre[std::make_pair(i, j)] = i;
            }
        }
        for (auto k : V) {
            for (auto i : V) {
                for (auto j : V) {
                    if (MultiSourceShortestPaths<TGraph>::dis.find(std::make_pair(i, k)) != MultiSourceShortestPaths<TGraph>::dis.end() && MultiSourceShortestPaths<TGraph>::dis.find(std::make_pair(k, j)) != MultiSourceShortestPaths<TGraph>::dis.end())
                    {
                        if (MultiSourceShortestPaths<TGraph>::dis.find(std::make_pair(i, j)) == MultiSourceShortestPaths<TGraph>::dis.end()) {
                            MultiSourceShortestPaths<TGraph>::dis[std::make_pair(i, j)] = MultiSourceShortestPaths<TGraph>::dis[std::make_pair(i, k)] + MultiSourceShortestPaths<TGraph>::dis[std::make_pair(k, j)];
                            MultiSourceShortestPaths<TGraph>::pre[std::make_pair(i, j)] = MultiSourceShortestPaths<TGraph>::pre.at(std::make_pair(k, j));
                        }
                        else if (MultiSourceShortestPaths<TGraph>::dis[std::make_pair(i, j)] > MultiSourceShortestPaths<TGraph>::dis[std::make_pair(i, k)] + MultiSourceShortestPaths<TGraph>::dis[std::make_pair(k, j)]) {
                            MultiSourceShortestPaths<TGraph>::dis[std::make_pair(i, j)] = MultiSourceShortestPaths<TGraph>::dis[std::make_pair(i, k)] + MultiSourceShortestPaths<TGraph>::dis[std::make_pair(k, j)];
                            MultiSourceShortestPaths<TGraph>::pre[std::make_pair(i, j)] = MultiSourceShortestPaths<TGraph>::pre.at(std::make_pair(k, j));
                        }
                    }
                }
            }
        }
    }
    ~FloydShortestPaths() {};
};

#endif