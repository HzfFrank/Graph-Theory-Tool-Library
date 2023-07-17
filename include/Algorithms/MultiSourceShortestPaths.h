#ifndef MULTI_SOURCE_SHORTEST_PATHS
#define MULTI_SOURCE_SHORTEST_PATHS

#include <vector>
#include <optional>
#include <queue>
#include <stack>
#include <Algorithms/BreadthFirstSearcher.h>

template <typename TGraph>
class MultiSourceShortestPaths {
private:
    const TGraph *graph;

protected:
    std::map<std::pair<int, int>, typename TGraph::TValue> dis;
    std::map<std::pair<int, int>, int> pre;
    BreadthFirstSearcher<TGraph> *b;
 public:
    static_assert(std::is_default_constructible<typename TGraph::TValue>::value && std::is_nothrow_default_constructible<typename TGraph::TValue>::value, "TValue requires default constructor");
    MultiSourceShortestPaths() = delete;
    explicit MultiSourceShortestPaths(const TGraph *graph) : graph(graph) {}
    virtual ~MultiSourceShortestPaths() {};
 public:
  bool HasPathOf(int source, int destination) const {
      std::function<bool(int)> check = [=](int x) -> bool { return destination == x; };
      if (b->TryFindFirstVertex(graph, source, check) == std::nullopt)
          return false;
      return true;
  }

  std::optional<typename TGraph::TValue> TryGetDistanceOf(int source, int destination) const {
      if (!HasPathOf(source, destination))
          return std::nullopt;
      return this->dis.at(std::make_pair(source, destination));
  }

  std::optional<std::vector<int>> TryGetShortestPathOf(int source, int destination) const {
      std::vector<int> ans;
      if (!HasPathOf(source, destination))
          return std::nullopt;
      std::stack<int> tmp;
      tmp.push(destination);
      while (tmp.top() != source)
      {
          tmp.push(this->pre.at(std::make_pair(source, tmp.top())));
      }
      tmp.push(source);
      while (!tmp.empty())
          ans.push_back(tmp.top()), tmp.pop();
      return ans;
  }
};

#endif
