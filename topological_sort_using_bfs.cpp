//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    queue<int> q;
    vector<int> order;
    vector<int> indegree(V+1,0);
    // find indegree of all the nodes
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
    return order;
}
