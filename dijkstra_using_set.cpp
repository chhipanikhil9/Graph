//Function to find the shortest distance of all the vertices from the source vertex src.
// Here graph is undirected weighted graph

#define pii pair<int,int> 
vector <int> dijkstra(int N, vector<vector<int>> adj[], int src)
{
    set<pii> st;
    vector<int> dis(N, INT_MAX);
    dis[src] = 0;
    st.insert({0, src});
    
    while (!st.empty()) {
        auto curNode = *(st.begin());
        st.erase(curNode);
        int cur = curNode.second;
        int d = curNode.first;
        
        // Already shortest so no need to change
        if (d > dis[cur])
            continue;
        
        for (auto nbrNode : adj[cur]) {
            int nbr = nbrNode[0];
            int nbrD = nbrNode[1];
            int nd = d + nbrD;
            if (nd < dis[nbr]) {
                st.erase({nbrD,nbr});// remove the old one
                dis[nbr] = nd;// update the distance
                st.insert({nd, nbr}); //and insert the new one with shortes distance
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (dis[i] == INT_MAX)
            dis[i] = -1;
    }
    return dis;
}
