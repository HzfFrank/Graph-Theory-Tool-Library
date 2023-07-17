#include <DataStructures/Graph.h>
#include <DataStructures/Edge.h>
#include <DataStructures/UndirectedGraph.h>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <assert.h>
#include <iostream>
#include <Algorithms/BreadthFirstSearcher.h>
#include <Algorithms/DepthFirstSearcher.h>
#include <Algorithms/DijkstraShortestPaths.h>
#include <Algorithms/ShortestPaths.h>
#include <Algorithms/BellmanFordShortestPaths.h>
#include <Algorithms/FloydShortestPaths.h>
using namespace std;

int main()
{
    /*Graph g;
    UndirectedGraph h;
    WeightedGraph<string> i;
    assert(g.AddVertex(1) == true);
    assert(g.AddVertex(2) == true);
    assert(g.AddVertex(3) == true);
    assert(g.AddVertex(3) == false);
    assert(g.AddVertex(4) == true);
    assert(g.ContainsVertex(4) == true);
    assert(g.RemoveVertex(4) == true);
    assert(g.ContainsVertex(4) == false);
    assert(g.RemoveVertex(5) == false);

    assert(g.AddEdge(1, 2) == true);
    assert(g.AddEdge(1, 3) == true);
    assert(g.AddEdge(2, 5) == false);
    assert(g.ContainsEdge(1, 2) == true);
    assert(g.ContainsEdge(2, 5) == false);

    assert(g.GetVertices().size() == g.CountVertices()); // 4
    assert(g.GetEdges().size() == 2);
    assert(g.GetIncomingEdges(1).size() == 0);
    assert(g.GetOutgoingEdges(1).size() == 2); // {{1, 2}, {1, 3}}
    assert(g.GetDegree(1) == 2);
    assert(g.GetNeighbors(1).size() == 2); // {2, 3}
    assert(g.GetNeighbors(2).size() == 0);*/

    /*auto *g = new Graph();
    for (int i = 1; i <= 6 ; ++i) {
        g->AddVertex(i);
    }
    g->AddEdge(1, 2);
    g->AddEdge(1, 4);
    g->AddEdge(2, 3);
    g->AddEdge(3, 4);
    g->AddEdge(4, 1);
    g->AddEdge(5, 6);
    g->AddEdge(6, 5);

    BreadthFirstSearcher<Graph>::VisitAllVertices(g, 1, [](int u) -> void {
        printf("%d", u);
    });
    puts("");
    BreadthFirstSearcher<Graph>::VisitAllVertices(g, 5, [](int u) -> void {
        printf("%d", u);
    });
    puts("");
    DepthFirstSearcher<Graph>::VisitAllVertices(g, 1, [](int u) -> void {
        printf("%d", u);
    });
    puts("");
    DepthFirstSearcher<Graph>::VisitAllVertices(g, 6, [](int u) -> void {
        printf("%d", u);
    });*/
    auto *g = new WeightedGraph<double>();
    for (int i = 1; i <= 6; ++i) {
        g->AddVertex(i);
    }
    g->AddEdge(1, 2, 1);
    g->AddEdge(2, 3, 2);
    g->AddEdge(3, 4, 3);
    g->AddEdge(4, 1, 4);
    g->AddEdge(5, 6, 5);
    g->AddEdge(6, 5, 6);

    ShortestPaths<WeightedGraph<double>> *p = nullptr;
    MultiSourceShortestPaths<WeightedGraph<double>> *q = nullptr;
    q = new FloydShortestPaths<WeightedGraph<double>>(g);
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (q->HasPathOf(i, j))
            {
                std::optional<double> oi = q->TryGetDistanceOf(i, j);
                cout << *oi << " ";
            }
            else
                printf(("NULL "));
        }
        printf("\n");
    }
    delete g;
    return 0;
}
