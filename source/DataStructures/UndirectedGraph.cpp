#include <DataStructures/UndirectedGraph.h>

UndirectedGraph::UndirectedGraph() : Graph()
{
    cnt = 0;
}

bool UndirectedGraph::AddEdge(int vertex1, int vertex2)
{
    if (Graph::ContainsEdge(vertex1, vertex2))
        return false;
    Graph::AddEdge(vertex1, vertex2);
    if (vertex1 != vertex2)
        Graph::AddEdge(vertex2, vertex1);
    else
        cnt++;
    return true;
}

bool UndirectedGraph::RemoveEdge(int vertex1, int vertex2)
{
    if (vertex1 != vertex2)
    {
        if (Graph::RemoveEdge(vertex1, vertex2) && Graph::RemoveEdge(vertex2, vertex1))
            return true;
    }
    else
    {
        if (Graph::RemoveEdge(vertex1, vertex2))
            return true;
    }
    return false;
}

int UndirectedGraph::CountEdges() const
{
    return UndirectedGraph::GetEdges().size();
}

std::vector<Edge> UndirectedGraph::GetEdges() const
{
    std::vector<Edge> tmp = Graph::GetEdges();
    std::vector<Edge> ans;
    for (auto it = tmp.begin(); it != tmp.end(); it++) {
        bool flag = true;
        for (auto s = ans.begin(); s != ans.end(); s++)
        {
            if (s->GetSource() == it->GetDestination() && s->GetDestination() == it->GetSource())
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            Edge e(it->GetSource(), it->GetDestination());
            ans.push_back(e);
        }
    }
    return ans;
}

int UndirectedGraph::GetDegree(int vertex) const
{
    int ans = Graph::GetDegree(vertex);
    if (ContainsEdge(vertex, vertex))
        ans++;
    return ans;
}
