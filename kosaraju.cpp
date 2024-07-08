// SCC: is a set of nodes in which their is path btween any two pair of nodes directly or indirectly.
// SCC: exist only in Directed Graph
// and it works that if we reverse the edges than it will not affect the SCC but it will break the connection with the other parts and it will become alone.

class Solution
{
public:
	vector<int> vis;
// to store the nodes on their finishing time in sorted order who finish first comes first.
void dfs(int src,vector<vector<int>>& adj,stack<int> &st){
    vis[src] = 1;
    for(int nbr:adj[src]){
        if(!vis[nbr]){
            dfs(nbr,adj,st);
        }
    }
    st.push(src);
}
// to count the components
void dfs2(int src,vector<int> adj[]){
    vis[src] = 1;
    for(int nbr:adj[src]){
        if(!vis[nbr]){
            dfs2(nbr,adj);
        }
    }
}
int kosaraju(int n,vector<vector<int>>& adj)
{
    // step1: store the time
    stack<int> st;
    vis.assign(n+1,false);
  
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,adj,st);
        }
    }
  
    // step2: reverse the edges
    vector<int> adjT[n];
    for(int u=0;u<n;u++){
        for(int v:adj[u]){
            adjT[v].push_back(u);
        }
    }
    // step3: now count the SCC
    vis.assign(n+1,false);
    int cnt = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            cnt++;
            dfs2(node,adjT);
        }
    }
    return cnt;
}
};
