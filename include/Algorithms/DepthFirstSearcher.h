#ifndef DEPTH_FIRST_SEARCHER
#define DEPTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <set>
#include <queue>
#include <stack>

template <typename TGraph>
class DepthFirstSearcher {
 public:
    static void dfs1(std::map<int, int> *vis, const TGraph *graph, int x, const std::function<void(int)> action){
        (*vis)[x] = 1;
        action(x);
        std::vector<int> neighbors = graph->GetNeighbors(x);
        for (auto j : neighbors)
            if (!(*vis)[j]) dfs1(vis, graph, j, action);
    }
    static std::optional<int> dfs2(std::map<int, int> *vis, const TGraph *graph, int x, const std::function<bool(int)> predicate){
        (*vis)[x] = 1;
        if (predicate(x)) return x;
        std::vector<int> neighbors = graph->GetNeighbors(x);
        for (auto j : neighbors)
            if (!(*vis)[j])
            {
                std::optional<int> tmp = dfs2(vis, graph, j, predicate);
                if (tmp != std::nullopt)
                    return tmp;
            }
        return std::nullopt;
    }
    static void VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action){
        if (!graph->ContainsVertex(start)) return;
        std::map<int, int> vis;
        dfs1(&vis, graph, start, action);
    }
    static std::optional<int> TryFindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate){
        if (!graph->ContainsVertex(start)) return std::nullopt;
        std::map<int, int> vis;
        return dfs2(&vis, graph, start, predicate);
    }
};

#endif
