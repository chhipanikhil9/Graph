vector<int> parent;// resize them in main
 vector<int> sz;
 void make(int u){
     parent[u] = u;
     sz[u] = 1;
 }

 int findParent(int u){
     if(parent[u]==u) return u;
     return parent[u] = find(parent[u]);
 }
 
 void Union(int u,int v){
     int ur = find(u);
     int vr = find(v);
     if(ur==vr) return;
     if(sz[ur]<sz[vr]) swap(ur,vr);
     parent[vr] = ur;
     sz[ur] += sz[vr];
 }


/* In class form
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
*/
