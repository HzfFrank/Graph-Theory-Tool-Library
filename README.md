# Graph Theory Tool Library
Here is a graph theory tool library, it provides several APIs for users to constructe graphs and operate on the graphs.

You can see the ```tests/01-hello-world.cpp``` for examples and perform your desired operations in it.

Here are the APIs and learn how to use it:

**```Edge```**

The ```Edge``` class represents a *directed edge*, which has a constructor, a destructor, and two interfaces:

- `Edge(int source, int destination)`：Construct an edge object starting from ```source``` and ending at ```destination```
- `~Edge()`：Destroy the edge
- `int GetSource() const`：Obtain the starting point's id
- `int GetDestination() const`：Obtain the endpoint's id

Using examples

```
Edge e(1, 2); // Create a directed edge from 1 to 2
assert(e.GetSource() == 1);
assert(e.GetDestination() == 2);
```

**```Graph```**

The ```Graph``` class represents a *directed and unweighted* graph, which has a constructor, destructor, and fourteen interfaces:

- `Graph()`：Construct a graph
- `~Graph()`：Destroy the graph
- `bool AddVertex(int vertex)`：Add a vertex with a specified number. If the addition is successful, return `true`. If the point already exists, return `false`
- `bool RemoveVertex(int vertex)`：Delete the vertex with the specified number. If the deletion is successful, return `true`. If the point does not exist, return `false`
- `bool AddEdge(int vertex1, int vertex2)`：Add a directed edge from `vertex1` to `vertex2`, if the addition is successful, return `true`, if the point does not exist or the edge already exists, return `false`
- `bool RemoveEdge(int vertex1, int vertex2)`：Delete the directed edge from `vertex1` pointing to `vertex2`, if the deletion is successful, return `true`, if the vertex does not exist or the edge does not exist, return `false`
- `int CountVertices() const`：Return the number of vertices
- `int CountEdges() const`：Return the number of edges
- `bool ContainsVertex(int vertex) const`：Determine whether the vertex with the specified number exists
- `bool ContainsEdge(int vertex1, int vertex2) const`：Determine whether the edge from `vertex1` to `vertex2` exists
- `std::vector<int> GetVertices() const`：Get a list of all vertices in the graph
- `std::vector<Edge> GetEdges() const`：Get a list of all edges in the graph
- `std::vector<Edge> GetIncomingEdges(int vertex) const`：Get the incoming edge list of a vertex, if the vertex does not exist, return an empty list
- `std::vector<Edge> GetOutgoingEdges(int vertex) const`：Get the outcoming edge list of a vertex, if the vertex does not exist, return an empty list
- `int GetDegree(int vertex) const`：Returns the degree of the vertex with the specified id (the degree of the directed graph is the out degree), and returns 0 if the vertex does not exist
- `std::vector<int> GetNeighbors(int vertex) const`：Get the neighbor list of a vertex (the neighbor of the directed graph is the vertex pointed to by the outgoing edge), if the vertex does not exist, return an empty list

Using examples

```
Graph g; // Build a new graph

assert(g.AddVertex(1) == true);
assert(g.AddVertex(2) == true);
assert(g.AddVertex(3) == true);
assert(g.AddVertex(3) == false); // Vertex 3 already exists
assert(g.AddVertex(4) == true);
assert(g.ContainsVertex(4) == true);
assert(g.RemoveVertex(4) == true);
assert(g.ContainsVertex(4) == false);
assert(g.RemoveVertex(5) == false);

assert(g.AddEdge(1, 2) == true);
assert(g.AddEdge(1, 3) == true);
assert(g.AddEdge(2, 5) == false); // Vertex 5 does not exist
assert(g.ContainsEdge(1, 2) == true);
assert(g.ContainsEdge(2, 5) == false);

assert(g.GetVertices().size() == g.CountVertices()); // 4
assert(g.GetEdges().size() == 2);
assert(g.GetIncomingEdges(1).size() == 0);
assert(g.GetOutgoingEdges(1).size() == 2); // {{1, 2}, {1, 3}}
assert(g.GetDegree(1) == 2);
assert(g.GetNeighbors(1).size() == 2); // {2, 3}
assert(g.GetNeighbors(2).size() == 0);
```

**```WeightedEdge```**

The ```WeightedEdge``` class represents a *directed edge* with an `int` type weight, which has a constructor, a destructor, and three interfaces:

- `WeightedEdge(int source, int destination, int weight)`：Construct an edge object starting from `source`, ending at `destination`, and the weight is `weight`
- `~WeightedEdge()`
- `int GetSource() const`
- `int GetDestination() const`
- `int GetWeight() const`：Obtain the weight of the edge

**```WeightedGraph```**

The `WeightedGraph` class represents a *directed graph* composed of *directed edges* with `int` type weights. It has a constructor, a destructor, and fifteen interfaces:

- `WeightedGraph()`
- `~WeightedGraph()`
- `bool AddVertex(int vertex)`
- `bool RemoveVertex(int vertex)`
- `bool AddEdge(int vertex1, int vertex2, int weight)`
- `bool RemoveEdge(int vertex1, int vertex2)`
- `int CountVertices() const`
- `int CountEdges() const`
- `bool ContainsVertex(int vertex) const`
- `bool ContainsEdge(int vertex1, int vertex2) const`
- `int GetWeight(int vertex1, int vertex2) const`：Query the weight of the edge from `vertex1` pointing to `vertex2`, if this edge does not exist, it is UB (Undefined Behavior) and will return 0
- `std::vector<int> GetVertices() const`
- `std::vector<WeightedEdge> GetEdges() const`
- `std::vector<WeightedEdge> GetIncomingEdges(int vertex) const`
- `std::vector<WeightedEdge> GetOutgoingEdges(int vertex) const`
- `int GetDegree(int vertex) const`
- `std::vector<int> GetNeighbors(int vertex) const`

**```UndirectedGraph```**

The `UndirectedGraph` class represents *undirected and unweighted graph*, and all interfaces of the it are exactly the same as the directed and unweighted graph (`Graph` class)

**```UndirectedWeightedGraph```**

The `UndirectedWeightedGraph` class represents *undirected weighted graph*, and all interfaces of it are exactly the same as the directed weighted graph (`WeightedGraph` class)

**```BreadthFirstSearcher```** and **```DepthFirstSearcher```**

- `void VisitAllVertices(const TGraph *graph, int start, const std::function<void(int)> &action)` means to traverse all traversable vertices from the starting vertex (`start`) in a width-first or depth-first manner, and Call the `action` operation on these vertices. `action` is called at most once per vertex.
- `std::optional<int> TryFindFirstVertex(const TGraph *graph, int start, const std::function<bool(int)> &predicate)` means to traverse all possible vertices from the starting point (start) in a width-first or depth-first manner Traverse the points and find the number of the first point that satisfies the predicate `predicate`. Since there may not be such a point, we use `std::optional<int>` as the return value type, which shows that it may be empty. If found, return the optional container containing the point number, otherwise, return an empty container.

**```DijkstraShortestPaths```**

- `DijkstraShortestPaths(const TGraph *graph, int source)`
- `~DijkstraShortestPaths()`
- `bool HasPathTo(int)`：Returns whether there is a path from the start vertex to the end vertex
- `std::optional<TValue> TryGetDistanceTo(int)`：Returns the weight of the shortest path from the start point to the end point. If there is no path, it returns empty. The distance from the start point is defined as the default value `TValue()` of `TValue` type.
- `std::optional<std::vector<int>> TryGetShortestPathTo(int)`：Returns the numbers of all vertices on a shortest path from the start vertex to the end vertex (including the start vertex and end vertex). If there are no vertices, it returns empty, and if there are multiple vertices, it returns a random one.
