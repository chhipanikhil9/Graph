// Bellmon Ford is used to find out the shortes path from src to all nodes(single source shortes path) 
// It is also used to find out the negetive weight cycle
// Time: O(EV) all edges(E) is relex for (V-1) times
// Space: O(V) for dis
bool bellmonFord(vector<vector<int>>& edges, int n, int k) {
    vector<int> dis(n+1,INT_MAX);
    dis[k] = 0;
    // relex all edges n-1 times
    for(int i=1;i<n;i++){
        for(auto e:edges){
            int u = e[0], v = e[1], w = e[2];
            if(dis[u]!=INT_MAX && dis[u]+w < dis[v]){
                dis[v] = dis[u]+w;
            }
        }
    }

  // find the negetive weight cycle
    for(auto e:edges){
        int u = e[0], v = e[1], w = e[2];
        // still it is giving the shortes path that mean it contains the negetive weight cycle
        if(dis[u]!=INT_MAX && dis[u]+w < dis[v]){
            cout<<"Cycle Exist"<<endl;
            return true;
        }
    }
    cout<<"Cycle does not exist"<<endl;
    return false;
}
