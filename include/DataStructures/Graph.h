#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <set>
#include <map>
#include <DataStructures/Edge.h>

class Graph {
 private:
    std::set<int> Vertices;
    std::map<int, std::vector<Edge>> Edges;
 public:
  Graph();
  ~Graph();
 public:
  bool AddVertex(int vertex);
  bool RemoveVertex(int vertex);
  virtual bool AddEdge(int vertex1, int vertex2);
  virtual bool RemoveEdge(int vertex1, int vertex2);
 public:
  int CountVertices() const;
  virtual int CountEdges() const;
  bool ContainsVertex(int vertex) const;
  bool ContainsEdge(int vertex1, int vertex2) const;
  std::vector<int> GetVertices() const;
  std::vector<Edge> GetEdges() const;
  std::vector<Edge> GetIncomingEdges(int vertex) const;
  std::vector<Edge> GetOutgoingEdges(int vertex) const;
  virtual int GetDegree(int vertex) const;
  std::vector<int> GetNeighbors(int vertex) const;
};

#endif
