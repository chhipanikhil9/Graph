// Khan's algo to find the cycle in Directed Graph: it uses the topological sort if the order contains all the vertices, 
// then there is no cycle else there is a cycle present in the graph
// For an un-directed graph this will not work use BFS with parent
bool isCyclePresent(int V, vector<int> adj[]) 
{
    // code here
    queue<int> q;
    vector<int> order;
    vector<int> indegree(V+1,0);
  
    //Find the in-degree of all the nodes
    for(int i=0;i<V;i++){
        for(auto nbr: adj[i]){
            indegree[nbr]++;
        }
    }
    
    // find nodes with 0 indegree;
    for(int i=0;i<V;i++){
           if(indegree[i]==0)
               q.push(i);
    }
    while(!q.empty()){
        int front = q.front();
        q.pop();
        order.push_back(front);
        for(auto nbr:adj[front]){
            indegree[nbr]--;
            if(indegree[nbr]==0)
                q.push(nbr);
        }  
    }
    return (order.size()==n);
}
