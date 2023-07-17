#include <DataStructures/Graph.h>

Graph::Graph() {
    Vertices.clear();
    Edges.clear();
}

Graph::~Graph() {
    Vertices.clear();
    Edges.clear();
}

bool Graph::AddVertex(int vertex)
{
    if (Vertices.count(vertex) > 0) return false;
    Vertices.insert(vertex);
    return true;
}

bool Graph::RemoveVertex(int vertex)
{
    if (Vertices.count(vertex) == 0) return false;
    Vertices.erase(vertex);
    return true;
}

int Graph::CountVertices() const
{
    return Vertices.size();
}

int Graph::CountEdges() const
{
    return GetEdges().size();
}

bool Graph::AddEdge(int vertex1, int vertex2)
{
    if (Vertices.find(vertex1) == Vertices.end()) return false;
    if (Vertices.find(vertex2) == Vertices.end()) return false;
    Edge e(vertex1, vertex2);

    if (Edges.find(vertex1) == Edges.end())
    {
        std::vector<Edge> tmp;
        tmp.push_back(e);
        Edges[vertex1] = tmp;
    }
    else
    {
        for (auto v : Edges[vertex1])
            if (v.GetDestination() == vertex2) return false;
        Edges[vertex1].push_back(e);
    }
    return true;
}

bool Graph::RemoveEdge(int vertex1, int vertex2)
{
    if (Vertices.find(vertex1) == Vertices.end()) return false;
    if (Vertices.find(vertex2) == Vertices.end()) return false;
    if (Edges.find(vertex1) == Edges.end()) return false;
    Edge e(vertex1, vertex2);
    for (auto it = Edges[vertex1].begin(); it != Edges[vertex1].end(); it++)
        if (it->GetDestination() == vertex2)
        {
            Edges[vertex1].erase(it);
            return true;
        }
    return false;
}

bool Graph::ContainsVertex(int vertex) const
{
    if (Vertices.find(vertex) == Vertices.end()) return false;
    return true;
}

bool Graph::ContainsEdge(int vertex1, int vertex2) const
{
    if (Vertices.find(vertex1) == Vertices.end()) return false;
    if (Vertices.find(vertex2) == Vertices.end()) return false;
    if (Edges.find(vertex1) == Edges.end()) return false;
    Edge e(vertex1, vertex2);
    for (auto it = Edges.at(vertex1).begin(); it != Edges.at(vertex1).end(); it++)
        if (it->GetDestination() == vertex2)
            return true;
    return false;
}

std::vector<int> Graph::GetVertices() const
{
    std::vector<int> ans;
    for (auto v : Vertices) {
        ans.push_back(v);
    }
    return ans;
}

std::vector<Edge> Graph::GetEdges() const
{
    std::vector<Edge> ans;
    for (auto it = Edges.begin(); it != Edges.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            ans.push_back(it->second[i]);
        }
    }
    return ans;
}

std::vector<Edge> Graph::GetIncomingEdges(int vertex) const
{
    std::vector<Edge> ans;
    for (auto it = Edges.begin(); it != Edges.end() ; it++) {
        auto tmp = it->second;
        for (auto v: tmp) {
            if (v.GetDestination() == vertex) ans.push_back(v);
        }
    }
    return ans;
}

std::vector<Edge> Graph::GetOutgoingEdges(int vertex) const
{
    std::vector<Edge> ans;
    for (auto it = Edges.begin(); it != Edges.end() ; it++) {
        auto tmp = it->second;
        for (auto v: tmp) {
            if (v.GetSource() == vertex) ans.push_back(v);
        }
    }
    return ans;
}

int Graph::GetDegree(int vertex) const {
    if (Edges.find(vertex) == Edges.end())
        return 0;
    else
        return Edges.at(vertex).size();
}

std::vector<int> Graph::GetNeighbors(int vertex) const {
    if (Edges.find(vertex) == Edges.end())
    {
        return  std::vector<int>();
    }
    std::vector<int> ans;
    auto tmp = Edges.find(vertex)->second;
    for (auto v : tmp) {
        ans.push_back(v.GetDestination());
    }
    return ans;
}
