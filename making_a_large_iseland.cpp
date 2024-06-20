// https://leetcode.com/problems/making-a-large-island/description/
// this problem can be done using DSU easily
class Solution {
public:
    int n;
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int i,int j,int &cnt,int clr,vector<vector<int>>& grid){
        grid[i][j] = clr;
        cnt++;
        for(int d=0;d<4;d++){
            int nx = i+dir[d][0],ny = j+dir[d][1];
            if(nx>=0 and nx<n and ny>=0 and ny<n and grid[nx][ny]==1){
                dfs(nx,ny,cnt,clr,grid);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        
        n = grid.size();
        int maxi = 0;
        map<int,int> sz;
        int clr = 2;

      // first color the graph so that we can get the component with its size in sz map
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int cnt = 0;
                    dfs(i,j,cnt,clr,grid);
                    sz[clr] = cnt;
                    maxi = max(maxi,cnt);
                    clr++;
                }
            }
        }

        // now find out that if we include a zero then what size do we get? and take max of that sizes
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int cnt = 1;
                    set<int> st;
                    for(int d=0;d<4;d++){
                        int nx = i+dir[d][0], ny = j+dir[d][1];
                        if(nx>=0 and nx<n and ny>=0 and ny<n and grid[nx][ny]!=0){
                            st.insert(grid[nx][ny]);
                        }
                    }
                    for(int x:st){
                        cnt += sz[x];
                    }
                    maxi = max(maxi,cnt);
                }
            }
        }

        return maxi;
    }
};
