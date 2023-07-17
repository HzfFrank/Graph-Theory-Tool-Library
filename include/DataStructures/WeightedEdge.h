#ifndef WEIGHTEDEDGE_H
#define WEIGHTEDEDGE_H
#include "Edge.h"
#include <map>

template <typename T>
class WeightedEdge : public Edge {
private:
    T weight;
public:
    WeightedEdge(int source, int destination, T weight) : Edge(source, destination), weight(weight) {};
    ~WeightedEdge() {};
public:
    T GetWeight() const {
        return weight;
    }
};

#endif
