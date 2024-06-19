// First choose any node and put in the pq. Then pick the node with the lowest edge related to this take node. and perform this until all vertices are not visited.
int spanningTree(int V, vector<vector<int>> adj[]){
  
    priority_queue<pii,vector<pii>,greater<pii>> q;
    vector<bool> vis(V,false);
    q.push({0,0});
    int sum = 0;
    
    while(!q.empty()){
        int d = q.top().first;
        int cur = q.top().second;
        q.pop();
        
        if(vis[cur]==1) continue;
        
        // add it to the mst
        vis[cur] = 1;
        sum += d;
        
        for(auto nbr:adj[cur]){
            if(!vis[nbr[0]]){
                q.push({nbr[1],nbr[0]});
            }
        }
    }
    return sum;
}
