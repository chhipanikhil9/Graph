
void dfs(vector<int> adj[],int src,vector<int> &order,vector<int> &vis){
  vis[src] = 1;
  
  for(auto nbr: adj[src]){
      if(vis[nbr]==0){
          dfs(adj,nbr,order,vis);
      }
  }
  order.push_back(src);
  return ;
}

//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
  // code here
  vector<int> order;
  vector<int> vis(V+1,0);
  for(int i=0;i<V;i++){
      if(vis[i]==0)
          dfs(adj,i,order,vis);
  }
  reverse(order.begin(),order.end());
  return order;
}
