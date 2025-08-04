// User function Template for C++

class Solution {
  public:
    vector<int> in,low,vis,ans;
    int timer = 0;
    void dfs(int node,int par,vector<int> adj[]){
        int child = 0;
        vis[node] = 1;
        in[node] = low[node] = timer++;
        for(int nbr:adj[node]){
            if(nbr==par) continue;
            if(!vis[nbr]){
                dfs(nbr,node,adj);
                low[node] = min(low[node],low[nbr]);
                if(in[node]<=low[nbr] && par!=-1){
                    ans[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node],in[nbr]);
            }
        }
      // deal parent saperately
        if(par==-1 && child>1){
            ans[node] = 1;
        }
    }
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        // Code here
        in.assign(n+1,0);
        low.assign(n+1,0);
        vis.assign(n+1,0);
        ans.assign(n+1,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,adj);
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(ans[i]) res.push_back(i);
        }
        if(res.size()==0) return {-1};
        return res;
    }
};
