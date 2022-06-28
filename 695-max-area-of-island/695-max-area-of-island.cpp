class Solution {
public:
    int dx[5] = {0,1,0,-1,0};
    int dfs(int x, int y, int n, int m, vector<vector<int>>&a){
        int sum = 1;
        a[x][y] = 0;
        for(int t = 0;t<4;t++){
            int newx = x + dx[t];
            int newy = y + dx[t+1];
            if(newx>=0 && newx<n && newy>=0 && newy<m && a[newx][newy]==1){
                sum+=dfs(newx,newy,n,m,a);
            }
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0 ;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    ans = max(ans,dfs(i,j,n,m,grid));
                }
            }
        }
        return ans;
    }
};