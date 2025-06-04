class Solution {
public:
    bool dfs(int node, vector<bool>& vis, vector<bool>& recStack, vector<int> adj[]) {
        vis[node] = true;
        recStack[node] = true;

        for (int nbr : adj[node]) {
            if (!vis[nbr]) {
                if (dfs(nbr, vis, recStack, adj)) return true;
            } else if (recStack[nbr]) {
                // Cycle detected
                return true;
            }
        }

        recStack[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]); // directed edge
        }

        vector<bool> vis(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, recStack, adj)) return true;
            }
        }

        return false;
    }
};
