#define pii pair<int,int>

class DisjointSet{
   public:
   
   vector<int> size;
   vector<int> parent;

  // constructor
   DisjointSet(int n){
       parent.assign(n+1,0);
       size.assign(n+1,1);
       for(int i=0;i<n;i++) {
            parent[i] = i;
            size[i] = 1;    
       }
   }
   
   int findParent(int u){
       if(parent[u]==u)
            return u;
         // path compression(reduces the time complexity)
        return parent[u] = findParent(parent[u]);
   }
   
   void unionBySize(int u,int v){
       int a = findParent(u);
       int b = findParent(v);
       if(a==b) return;
       // union by size
       if(a<b) swap(a,b);// always make a>b so a can be parent of b
        parent[b] = a;
        size[a] += size[b];
   }
};

class Solution
{
public:
//Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int n, vector<vector<int>> adj[])
  {
      // code here
      vector<pair<int,pii>> edges;
      for(int i=0;i<n;i++){
          for(auto nbr:adj[i]){
              edges.push_back({nbr[1],{i,nbr[0]}});
          }
      }
      sort(edges.begin(),edges.end());
      DisjointSet ds(n);
      int sum = 0;
      for(auto e:edges){
          int wt = e.first;
          int u = e.second.first;
          int v = e.second.second;
          if(ds.findParent(u)!=ds.findParent(v)){
              sum += wt;
              ds.unionBySize(u,v);
          }
      }
      return sum;
  }
};
