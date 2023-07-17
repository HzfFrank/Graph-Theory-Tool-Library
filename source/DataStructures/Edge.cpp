#include <DataStructures/Edge.h>

int Edge::GetSource() const {
    return source;
}

int Edge::GetDestination() const {
    return destination;
}

void Edge::ChangeEdge(int s, int d)
{
    this->source = s;
    this->destination = d;
}
