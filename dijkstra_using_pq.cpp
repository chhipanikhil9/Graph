// dijkstra will not work for negetive edge weights(Directed weighted cyclic and acyclic will work fine)
// And there is no profit to apply this on undirected graph bcs bfs gives the nice time complexity for undirected unweighted graph

/* Dijkstra using Priority Queue(Min Heap) */

#define pii pair<int, int>

vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
    // Weighted graph
    vector<pii> adj[N];
    for (auto e : edges) {
        adj[e[0]].push_back({e[1], e[2]}); // u -> {v, w}
    }
    
    priority_queue<pii, vector<pii>, greater<pii>> q; // min heap {dis, node}
    vector<int> dis(N, INT_MAX);
    dis[0] = 0;
    q.push({0, 0});
    
    while (!q.empty()) {
        int cur = q.top().second;
        int d = q.top().first;
        q.pop();
        
        // Already shortest so no need to change
        if (dis[cur] < d)
            continue;
        
        for (pii nbrNode : adj[cur]) {
            int nbr = nbrNode.first;
            int nbrD = nbrNode.second;
            int nd = d + nbrD;
            if (nd < dis[nbr]) {
                dis[nbr] = nd;
                q.push({nd, nbr});
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (dis[i] == INT_MAX)
            dis[i] = -1;
    }
    return dis;
}
