#include <DataStructures/WeightedGraph.h>

/*template <typename T>
bool WeightedGraph<T>::AddEdge(int vertex1, int vertex2, T weight) {
    bool status = Graph::AddEdge(vertex1, vertex2);
    if (status == false) return status;
    G[std::make_pair(vertex1, vertex2)] = weight;
    return true;
}*/

/*template <typename T>
T WeightedGraph<T>::GetWeight(int vertex1, int vertex2) const {
    if (ContainsEdge(vertex1, vertex2)) return G.at(std::make_pair(vertex1, vertex2));
    return 0;
}*/

/*template <typename T>
std::vector<WeightedEdge<T>> WeightedGraph<T>::GetIncomingEdges(int vertex) const {
    std::vector<Edge> t = Graph::GetIncomingEdges(vertex);
    std::vector<WeightedEdge<T>> ans;
    for (auto tmp : t)
    {
        WeightedEdge e(tmp.GetSource(), tmp.GetDestination(), GetWeight(tmp.GetSource(), tmp.GetDestination()));
        ans.push_back(e);
    }
    return ans;
}*/

/*template <typename T>
std::vector<WeightedEdge<T>> WeightedGraph<T>::GetOutgoingEdges(int vertex) const {
    std::vector<Edge> t = Graph::GetOutgoingEdges(vertex);
    std::vector<WeightedEdge<T>> ans;
    for (auto tmp : t)
    {
        WeightedEdge e(tmp.GetSource(), tmp.GetDestination(), GetWeight(tmp.GetSource(), tmp.GetDestination()));
        ans.push_back(e);
    }
    return ans;
}*/