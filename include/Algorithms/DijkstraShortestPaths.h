#ifndef DIJKSTRASHORTESTPATHS
#define DIJKSTRASHORTESTPATHS

#include <Algorithms/ShortestPaths.h>
#include <queue>
#include <stack>

template <typename TGraph>
class DijkstraShortestPaths : public ShortestPaths<TGraph> {
public:
    DijkstraShortestPaths(const TGraph *graph, int source) : ShortestPaths<TGraph>(graph, source) {
        static_assert(std::is_default_constructible<typename TGraph::TValue>::value, "TValue requires default constructor");
        typedef std::pair<typename TGraph::TValue, int> P;
        std::priority_queue<P, std::vector<P>, std::greater<P>> Q;
        Q.push(P(typename TGraph::TValue(), source));
        ShortestPaths<TGraph>::dis[source] = typename TGraph::TValue();
        std::vector<WeightedEdge<typename TGraph::TValue>> E;
        while (!Q.empty()) {
            P o = Q.top(); Q.pop();
            int t = o.second;
            if (ShortestPaths<TGraph>::dis[t] < o.first) continue;
            E = graph->GetOutgoingEdges(t);
            for (auto j : E) {
                int e = j.GetDestination();
                typename TGraph::TValue v = j.GetWeight();
                typename TGraph::TValue tmp = ShortestPaths<TGraph>::dis[t] + v;
                if (ShortestPaths<TGraph>::dis.find(e) == ShortestPaths<TGraph>::dis.end()) {
                    ShortestPaths<TGraph>::pre[e] = t;
                    ShortestPaths<TGraph>::dis[e] = tmp;
                    Q.push(P(tmp, e));
                }
                else if (ShortestPaths<TGraph>::dis[e] > tmp) {
                    ShortestPaths<TGraph>::pre[e] = t;
                    ShortestPaths<TGraph>::dis[e] = tmp;
                    Q.push(P(tmp, e));
                }
            }
        }
    }
    ~DijkstraShortestPaths() {};
};

#endif
