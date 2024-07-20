//In class form
class DisjointSet{
   vector<int> sz;
   vector<int> parent;
   public:
   
   DisjointSet(int n){
       parent.assign(n+1,0);
       sz.assign(n+1,1);
       for(int i=0;i<n;i++) {
            parent[i] = i;
            sz[i] = 1;    
       }
   }
   
   int findParent(int u){
       if(parent[u]==u)
            return u;
        return parent[u] = findParent(parent[u]);
   }
   
   void unionBySize(int u,int v){
       int ur = findParent(u);
       int vr = findParent(v);
       if(ur==vr) return;
       if(sz[ur]<sz[vr]) swap(ur,vr);// always make ur>vr so ur can be parent of vr
        parent[vr] = ur;
        sz[ur] += sz[vr];
   }
};


/* without class
vector<int> parent;// resize them in main
 vector<int> sz;
 void make(int u){
     parent[u] = u;
     sz[u] = 1;
 }

 int findParent(int u){
     if(parent[u]==u) return u;
     return parent[u] = findParent(parent[u]);
 }
 
 void Union(int u,int v){
     int ur = findParent(u);
     int vr = findParent(v);
     if(ur==vr) return;
     if(sz[ur]<sz[vr]) swap(ur,vr);
     parent[vr] = ur;
     sz[ur] += sz[vr];
 }

*/



