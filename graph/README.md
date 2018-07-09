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
