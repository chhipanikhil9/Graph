# Graph
## Single Source Shortest Path(SSSP)
1. [BFS](bfs.cpp): O(V+E)
2. [Dijkstra](dijkstra_using_pq.cpp)[Using Priority Queue(Best)]: O((V+E)logV)
3. [Dijkstra](dijkstra_using_set.cpp)[Using set(when update is required)]: O((V+E)logV)
4. [Bellman-Ford](bellman_ford.cpp): O(VE)


## All Pair Shortest Path
1. [Floyd-Warshall](floyd_warshall.cpp): O(N^3)

## Topological Sort
1. [Topological sort](topological_sort_using_bfs.cpp)[Using BFS]
2. [Topological sort](topological_sort_using_dfs.cpp)[Using DFS]
3. Questions:
   1. https://codeforces.com/problemset/problem/825/E

## Disjoint Set (Union-Find) Data Structure
1. [DSU using size](dsu_by_size.cpp)
2. [DSU using rank](dsu_by_rank.cpp)
### Problems:
1. [city and flood](https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/)
2. [city and campers](https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/)
3. [city and fireman vincent](https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-fireman-vincent/)
4. [city and soldiers](https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-soldiers/)
5. [city and campers 2](https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers-2/)
6. [colourful array](https://www.spoj.com/problems/CLFLARR/) Nice problem🔥🔥🤯🤯
7. [Remove Max Number of Edges to Keep Graph Fully Traversable](https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/?envType=daily-question&envId=2024-06-30)

## Cycle Detection
1. [Khan's Algorithm](khans_algo.cpp)[BFS for topological sort]: It only works for Directed Graph.
2. Union-Find Method: Uses the Union-Find data structure to detect cycles during the union operation. It only works for an Un-Directed Graph
3. DFS Method: Uses depth-first search to detect back edges. It works for both but in the Directed Graph it need the extra space to track that the the back edge is for the current path that is in the recursion stack. (see the [code](cycle_in_DG.cpp) for better understanding);

## Minimum Spanning Tree(MST)
1. [Prim's Algo](prims_algo.cpp)
    1. [Kingdom and its Roads](https://www.hackerearth.com/problem/algorithm/kingdom-and-its-roads/) 
2. [Cruskal's Algo](kruskals_algo.cpp)

## Strongly connected components(scc) -> Kosaraju Algo: follow three steps:
1. Sort the nodes on the basis of finishing time of dfs.
2. Reverese the edges
3. Run the dfs on nodes in their sorted finishing time.
4. [Code](kosaraju.cpp)

## Problem Patterns
1. [Graph Coloring](making_a_large_iseland.cpp)

## Shortest Path Algorithms and Problems(Striver's sheet)
1. https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
2. https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
3. https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
4. https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
5. https://leetcode.com/problems/network-delay-time/description/
6. https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
7. https://leetcode.com/problems/path-with-minimum-effort/description/
8. https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
9. https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
10. https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
11. https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
12. https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/



## [Monotonic Stack Resource:](https://itnext.io/monotonic-stack-identify-pattern-3da2d491a61e)
## [sweep-line concept](https://leetcode.com/discuss/study-guide/2166045/line-sweep-algorithms)
