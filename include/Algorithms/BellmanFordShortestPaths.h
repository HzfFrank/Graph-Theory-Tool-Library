#ifndef BELLMANFORDSHORTESTPATHS
#define BELLMANFORDSHORTESTPATHS

#include <Algorithms/ShortestPaths.h>
#include <queue>
#include <stack>

template <typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph> {
public:
    BellmanFordShortestPaths(const TGraph *graph, int source) : ShortestPaths<TGraph>(graph, source) {
        static_assert(std::is_default_constructible<typename TGraph::TValue>::value, "TValue requires default constructor");
        ShortestPaths<TGraph>::dis[source] = typename TGraph::TValue();
        std::vector<int> V = graph->GetVertices();
        for (int i = 1; i < graph->CountVertices(); ++i) {
            for (auto t : V) {
                if (ShortestPaths<TGraph>::dis.find(t) == ShortestPaths<TGraph>::dis.end())
                    continue;
                std::vector<WeightedEdge<typename TGraph::TValue>> E;
                E = graph->GetOutgoingEdges(t);
                for (auto j : E) {
                    int e = j.GetDestination();
                    typename TGraph::TValue v = j.GetWeight();
                    typename TGraph::TValue tmp = ShortestPaths<TGraph>::dis[t] + v;
                    if (ShortestPaths<TGraph>::dis.find(e) == ShortestPaths<TGraph>::dis.end())
                    {
                        ShortestPaths<TGraph>::dis[e] = tmp;
                        ShortestPaths<TGraph>::pre[e] = t;
                    }
                    else if (ShortestPaths<TGraph>::dis[e] > tmp)
                    {
                        ShortestPaths<TGraph>::pre[e] = t;
                        ShortestPaths<TGraph>::dis[e] = tmp;
                    }
                }
            }
        }
        for (int i = 1; i < graph->CountVertices(); ++i) {
            for (auto t : V) {
                if (ShortestPaths<TGraph>::dis.find(t) == ShortestPaths<TGraph>::dis.end())
                    continue;
                std::vector<WeightedEdge<typename TGraph::TValue>> E;
                E = graph->GetOutgoingEdges(t);
                for (auto j : E) {
                    int e = j.GetDestination();
                    typename TGraph::TValue v = j.GetWeight();
                    typename TGraph::TValue tmp = ShortestPaths<TGraph>::dis[t] + v;
                }
            }
        }
    }
    ~BellmanFordShortestPaths() {};
};

#endif
