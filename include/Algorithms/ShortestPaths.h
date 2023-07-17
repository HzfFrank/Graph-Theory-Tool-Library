#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>
#include <queue>
#include <stack>
#include <Algorithms/BreadthFirstSearcher.h>

template <typename TGraph>
class ShortestPaths {
private:
    const TGraph *graph;
    int source;
protected:
    std::map<int, typename TGraph::TValue> dis;
    std::map<int, int> pre;
    BreadthFirstSearcher<TGraph> *b;
 public:
    static_assert(std::is_default_constructible<typename TGraph::TValue>::value && std::is_nothrow_default_constructible<typename TGraph::TValue>::value, "TValue requires default constructor");
    ShortestPaths() = delete;
    ShortestPaths(const TGraph *graph, int source) : graph(graph), source(source) {}
    virtual ~ShortestPaths() {};
 public:
    bool HasPathTo(int destination) const {
        std::function<bool(int)> check = [=](int x) -> bool { return destination == x; };
        if (b->TryFindFirstVertex(graph, source, check) == std::nullopt)
            return false;
        return true;
    }

    std::optional<typename TGraph::TValue> TryGetDistanceTo(int destination) const {
        if (!HasPathTo(destination))
            return std::nullopt;
        return this->dis.at(destination);
    }

    std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const {
        std::vector<int> ans;
        if (!HasPathTo(destination))
            return std::nullopt;
        std::stack<int> tmp;
        tmp.push(destination);
        while (tmp.top() != source)
            tmp.push(this->pre.at(tmp.top()));
        ans.push_back(source);
        while (!tmp.empty())
            ans.push_back(tmp.top()), tmp.pop();
        return ans;
    }
};

#endif
