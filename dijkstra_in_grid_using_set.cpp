// we can update in the priority queue that's why we use the set in dijkstra.
// if in the question no update required than the priority queue is best other wise use the set version

vector<vector<int>> dir = {{0,-1},{-1,0},{0,1},{1,0}};
int minimumEffortPath(vector<vector<int>>& grid) {
    int m = grid.size(),n = grid[0].size();
    set<vector<int>> st;// {max diff,i,j};
    vector<vector<int>> dis(m+1,vector<int>(n+1,INT_MAX));
    st.insert({0,0,0});
    dis[0][0] = 0;
    int mini = INT_MAX;
    while(!st.empty()){
        auto cur = *(st.begin());
        st.erase(cur);
        int d = cur[0];
        int x = cur[1];
        int y = cur[2];
        if(x==m-1 and y==n-1)
            return d; 
        for(int i=0;i<4;i++){
            int nx = x+dir[i][0];
            int ny = y+dir[i][1];
            if(nx>=0 and nx<m and ny>=0 and ny<n){
                int cost = max(d,abs(grid[nx][ny]-grid[x][y]));
                if(cost<dis[nx][ny]){
                    dis[nx][ny] = cost;
                    st.erase({dis[nx][ny],nx,ny});
                    st.insert({cost,nx,ny}); 
                }
            }
        }
    }
    return -1;
}
