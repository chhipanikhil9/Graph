#define pii pair<int,int>

class DisjointSet{
   public:
   
   vector<int> size;
   vector<int> parent;
   
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
        return parent[u] = findParent(parent[u]);
   }
   
   void unionBySize(int u,int v){
       int a = findParent(u);
       int b = findParent(v);
       if(a==b) return;
       
       if(a<b) swap(a,b);// always make a>b so a can be parent of b
        parent[b] = a;
        size[a] += size[b];
   }
};
