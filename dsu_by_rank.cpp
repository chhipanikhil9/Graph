#define pii pair<int,int>

class DisjointSet{
   public:
   
   vector<int> rank;
   vector<int> parent;
   
   DisjointSet(int n){
       parent.assign(n+1,0);
       rank.assign(n+1,0);
       for(int i=0;i<n;i++) {
            parent[i] = i;
            rank[i] = 0;    
       }
   }
   
   int findParent(int u){
       if(parent[u]==u)
            return u;
        return parent[u] = findParent(parent[u]);
   }
   
   void unionByRank(int u,int v){
       int rootU = findParent(u);
       int rootV = findParent(v);
       if(rootU==rootV) return;

       // make small rank root to child of the big rank root
       if(rootU<rootV){
          parent[rootU] = rootV;
       }
       else if(rootV<rootU){
         parent[rootV] = rootU;
       }
       else{
         parent[rootV] = rootU;
         rank[rootU]++;
       }
   }
};
