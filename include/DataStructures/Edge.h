#ifndef EDGE_H
#define EDGE_H

class Edge {
  private:
    int source, destination;
  public:
    Edge(int source, int destination) : source(source), destination(destination) {}
    ~Edge() {};
  public:
    int GetSource() const;
    int GetDestination() const;
  public:
    void ChangeEdge(int s, int d);
 };

#endif
