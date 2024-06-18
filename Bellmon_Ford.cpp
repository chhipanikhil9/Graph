// Bellmon Ford is used to find out the shortest path from src to all nodes(single source shortest path) 
// It is also used to find out the negative weight cycle
// Time: O(EV) all edges(E) is relex for (V-1) times
// Space: O(V) for dis

vector<int> bellman_ford(int n, vector<vector<int>>& edges, int src) {
    // Code here
    vector<int> dis(n,INT_MAX);
    dis[src] = 0;
    for(int i=0;i<n-1;i++){
        for(auto e:edges){
            int u = e[0],v = e[1], w = e[2];
            if(dis[u]!=INT_MAX && dis[u]+w<dis[v]){
                dis[v] = dis[u]+w;
            }
        }
    }
    for(auto e:edges){
        int u = e[0],v = e[1], w = e[2];
        // Still it is giving the shortest path that mean, it contains the negative weight cycle
        if(dis[u]!=INT_MAX && dis[u]+w<dis[v]){
            cout<<"Negative Weight Cycle exist"<<endl;
            return {-1};
        }
    }
    // Negative Weight Cycle does not exist so return the shortest path from the src
    return dis;
}
