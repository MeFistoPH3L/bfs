# Width-first search
A breadth-first search (breadth-first search) is one of the main algorithms on graphs.

A breadth-first search finds the path of shortest length in an unweighted graph, i.e. the path containing the smallest number of edges.

The algorithm works for O (n+m), where n is the number of vertices, m is the number of edges.

# Algorithm description
The input of the algorithm is a given graph (unweighted), and the number of the starting vertex __s__. The graph can be either oriented or undirected, it does not matter for the algorithm.

The algorithm itself can be understood as a process of "igniting" the graph: at step zero we ignite only vertex s. At each next step the fire from each already burning vertex is transferred to all its neighbors, i.e. in one iteration of the algorithm the "ring of fire" expands in width by one (hence the name of the algorithm).

More strictly, this can be represented as follows. Let's create a queue __q__, in which the burning vertices will be placed, and set up a Boolean array __used[]__, in which for each vertex we will mark whether it is already burning or not (or in other words, whether it has been visited).

Initially, only vertex __s__ is placed in the queue, and __used[s] = true__, and for all other vertices __used[] = false__. Then the algorithm is a cycle: while the queue is not empty, take out one vertex from its head, look through all edges coming from that vertex, and if some of the looked through vertices are not yet lit, light them up and put them to the end of the queue.

As a result, when the queue is empty, the traversal in width will bypass all vertices reachable from __s__, and each vertex will be reached by the shortest path. You can also calculate the lengths of shortest paths (for this you just need an array of path lengths __d[]__), and compactly save enough information to restore all these shortest paths (for this you need an array of "ancestors" __p[]__, in which for each vertex store the number of vertices, by which we got to this vertex).
