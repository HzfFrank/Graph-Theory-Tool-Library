#ifndef BREADTH_FIRST_SEARCHER
#define BREADTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <set>
#include <queue>

template <typename TGraph>
class BreadthFirstSearcher {
 public:
  static void VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action) {
      if (!graph->ContainsVertex(start))
          return;
      std::queue<int> Q;
      std::map<int, int> vis;
      std::vector<int> neighbors;
      vis[start] = 1;
      Q.push(start);
      for (; !Q.empty(); Q.pop()) {
          int t = Q.front();
          action(t);
          neighbors = graph->GetNeighbors(t);
          for (auto j : neighbors) {
              if (!vis[j])
                  vis[j] = 1, Q.push(j);
          }
      }
  }

  static std::optional<int> TryFindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate){
      if (!graph->ContainsVertex(start))
          return std::nullopt;
      std::queue<int> Q;
      std::map<int, int> vis;
      std::vector<int> neighbors;
      vis[start] = 1;
      Q.push(start);
      for (; !Q.empty(); Q.pop()) {
          int t = Q.front();
          if (predicate(t)) return t;
          neighbors = graph->GetNeighbors(t);
          for (auto j : neighbors) {
              if (!vis[j])
                  vis[j] = 1, Q.push(j);
          }
      }
      return std::nullopt;
  }
};

#endif