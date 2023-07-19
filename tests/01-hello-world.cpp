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
