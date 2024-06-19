# Graph
## Single Source Shortest Path(SSSP)
1. [BFS](bfs.cpp): O(V+E)
2. [Dijkstra](dijkstra_using_pq.cpp)[Using Priority Queue(Best)]: O((V+E)logV)
3. [Dijkstra](dijkstra_using_set.cpp)[Using set(when update is required)]: O((V+E)logV)
4. [Bellman-Ford](bellman_ford.cpp): O(VE)


## All Pair Shortest Path
1. [Floyd-Warshall](floyd_warshall.cpp): O(N^3)

## Topological Sort
1. [Topological sort](topologica_sort_using_bfs.cpp)[Using BFS]
2. [Topological sort](topologica_sort_using_dfs.cpp)[Using DFS]

## Disjoint Set (Union-Find) Data Structure
1. [DSU using size](dsu_using_size.cpp)
2. [DSU using rank](dsu_using_rank.cpp)
### Problems:
1. [city and flood](https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/)
2. [city and campers](https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/)
3. [city and fireman vincent](https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-fireman-vincent/)
4. [city and soldiers](https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-soldiers/)
5. [city and campers 2](https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers-2/)

## Cycle Detection
1. [Khan's Algorithm](khans_algo.cpp)[BFS for topological sort]: It only works for Directed Graph.
2. Union-Find Method: Uses the Union-Find data structure to detect cycles during the union operation. It only works for an Un-Directed Graph
3. DFS Method: Uses depth-first search to detect back edges. It works for both.

## Minimum Spanning Tree(MST)
1. [Prim's Algo](prims_algo.cpp)
2. [Cruskal's Algo](kruskals_algo.cpp)
