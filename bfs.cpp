// Bfs for finding the shortest path in Undirected Graph 
// can not use the dijkstra bcs bfs work only if the weights of all the edges is 1. 
// otherwise we will use dijkstra
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(N,-1);
        vector<bool> vis(N,false);
        queue<int> q;
        q.push(src);
        vis[src] = true;
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int cur = q.front();
                q.pop();
                ans[cur] = lvl;
                for(int nbr:adj[cur]){
                    if(!vis[nbr]){
                        q.push(nbr);
                        vis[nbr] = true;
                    }
                }
            }
            lvl++;
        }
        return ans;
    }
