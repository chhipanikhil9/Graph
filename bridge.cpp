// Time: O(E+V)
class Solution {
public:
    vector<int> inTime, lowTime,vis;
    int timer = 0;
    void dfs(int node,int par,vector<int> adj[],vector<vector<int>> &ans){
        vis[node] = true;
        lowTime[node] = inTime[node] = timer++;
        for(int nbr:adj[node]){
            if(nbr==par) continue;
            if(!vis[nbr]){
                dfs(nbr,node,adj,ans);
                lowTime[node] = min(lowTime[node],lowTime[nbr]);
                if(inTime[node]<lowTime[nbr]){
                    ans.push_back({node,nbr});
                }
            }
            else{
                lowTime[node] = min(lowTime[node],lowTime[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n+1];
        for(auto e:connections){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        inTime.assign(n+1,0);
        lowTime.assign(n+1,0);
        vis.assign(n+1,false);
        vector<vector<int>> ans;
        dfs(0,-1,adj,ans);
        return ans;
    }
};
