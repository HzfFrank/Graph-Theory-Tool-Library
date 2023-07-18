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

**```Graph```**

The ```Graph``` class represents a *directed and unweighted* graph, which has a constructor, destructor, and fourteen interfaces:

- `Graph()`：Construct a graph
- `~Graph()`：Destroy the graph
- `bool AddVertex(int vertex)`：Add a vertex with a specified number. If the addition is successful, return 'true'. If the point already exists, return 'false'
- `bool RemoveVertex(int vertex)`：Delete the vertex with the specified number. If the deletion is successful, return 'true'. If the point does not exist, return 'false'
- `bool AddEdge(int vertex1, int vertex2)`：Add a directed edge from 'vertex1' to 'vertex2', if the addition is successful, return 'true', if the point does not exist or the edge already exists, return 'false'
- `bool RemoveEdge(int vertex1, int vertex2)`：Delete the directed edge from 'vertex1' pointing to 'vertex2', if the deletion is successful, return 'true', if the vertex does not exist or the edge does not exist, return 'false'
- `int CountVertices() const`：Return the number of vertices
- `int CountEdges() const`：Return the number of edges
- `bool ContainsVertex(int vertex) const`：Determine whether the vertex with the specified number exists
- `bool ContainsEdge(int vertex1, int vertex2) const`：Determine whether the edge from 'vertex1' to 'vertex2' exists
- `std::vector<int> GetVertices() const`：Get a list of all vertices in the graph
- `std::vector<Edge> GetEdges() const`：Get a list of all edges in the graph
- `std::vector<Edge> GetIncomingEdges(int vertex) const`：Get the incoming edge list of a vertex, if the vertex does not exist, return an empty list
- `std::vector<Edge> GetOutgoingEdges(int vertex) const`：Get the outcoming edge list of a vertex, if the vertex does not exist, return an empty list
- `int GetDegree(int vertex) const`：Returns the degree of the vertex with the specified id (the degree of the directed graph is the out degree), and returns 0 if the vertex does not exist
- `std::vector<int> GetNeighbors(int vertex) const`：Get the neighbor list of a vertex (the neighbor of the directed graph is the vertex pointed to by the outgoing edge), if the vertex does not exist, return an empty list
