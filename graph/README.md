Simple graph algorithms:
=
ADT: adjacent list.

1. DFS(depth-first search): Given a src vertex, searching through its
neighbors as src vertex(implemented recursively), mark all visited
vertex. If arrived at destination, return, else if no un-marked
neighbor vertexes of current src vertex, we return to previous
vertex to visit next unvisited vertex.
>
This algorithm can be used to test if a graph is connected or find a path
between 2 vertexes.

2. BFS(breadth-first search): Given a src vertex, put all its
*unmarked* neighbor vertexes into a queue and mark both(consider
also record their distances from src vertex). Retrieve from the queue
head and if no vertexes left the process ends. Do the same for the
vertexes get from queue(until some destination reached).
>
This algorithm is suited for searching for the shortest path between
2 vertexes.

DEF: MST(minimum spanning tree): An MST is a spanning tree
(connected subgraph of the original graph includes all vertexes
with minimum edges included) of an edge-weighted graph which has
minimum total weight of its
edges.

3. Prim's algorithm is used to find the MST. It uses the *Cut 
Property* of graph.
>
*Cut Property*: Select any subset of the whole vertexes, the edge that
connects the subset and the remainder vertexes which has the minimum
weight is in MST(if multiple edges satisfy, select any of them is okay).

4. Kruskal's algorithm: (MST). Sort the edges by weight, add
edges to MST from smallest to largest, if adding any edge
forms a cycle, skip to next edge. Till V-N[connected trees].
>
Prim finds MST in connected graph, Kruskal finds MST in forest.
Prim can also be adjusted to forest condition, though a little bit
complicate. Both of the MST algo has O(ElgE) complexity. The Chazelle
algorithm is very near O(E) but complex and not that fast in real cases.
So *in general*, use of P and K are okay.

DEF: SPT(shortest-path tree): An SPT is a spanning tree
(connected subgraph of the original graph includes all vertexes
with minimum edges included) of an edge-weighted graph which gives
a shortest path from a src vertex to every reachable vertexes.

5. Dijkstra's algorithm: It implements *relax* method to solve the
single-source SPT problem in weighted graph with *non-negative weights*.
Its complexity is O(ElgV).
>
Relax method: for any target vertex, its distance to the given
src vertex should satisfy that, for any other vertex which has an
edge destinates the target, this edge weight plus the distance
from the other vertex should never be larger than it.

DEF: edge-weighted DAG(directed acyclic graph).
6. Topological sort algorithm is optimized for edge-weighted DAG which
may contain negative weights. In this algorithm each vertex is relaxed
once so is much optimized, compared to the Dijkstra's algorithm. Its
complexity is O(V+E).
>
Topological sort: A spanning tree of the original digraph which
satisfies that no vertex can be reached from another vertex in
the original digraph shall appear as the ancestor of the another
vertex in the topological sorted tree. There may be multiple
sorts satisfing it.

6. Bellman-Ford algorithm: for no *negative cycles* digraphs. This
algorighm can have cycles which is non-negative weights(or the negative
cycles do not sits any possible path from src to dst vertex), and
weights can be negative. It is a more general algorithm than the above
2 to solve the shortest path problem.
The Bellman-Ford algorithm can be described briefly by:
```
for (int pass = 0; pass < G.V(); pass++)
    for (v = 0; v < G.V(); v++)
        for (DirectedEdge e : G.adj(v))
            relax(e);
```
And thus its complexity in time is O(EV), in space is O(v). Its worst case
time consuming is worse than Dijkstra and Topo sort.
>
From algo 4th Strawman III, the attempt to find the shortest simple path
(which is acyclic) reachable from src is too difficult takes exponential time.
