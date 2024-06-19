// Multisourse shortes path Algo
// time: O(N^3) it is a dp solution
// space: O(N^2)// for adjcency matrix
vector<vector<int>> floyedWarshall(int n, int m, vector<vector<int>>& edges) {
  vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
  for (auto it : edges) {
    dist[it[0]][it[1]] = it[2];
    dist[it[1]][it[0]] = it[2];
  }
  // dist[i][i] = 0;
  for (int i = 0; i < n; i++) dist[i][i] = 0;

  for (int vis = 0; vis < n; via++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)
          continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
return dist;
}
