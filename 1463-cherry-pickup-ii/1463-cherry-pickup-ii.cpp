class Solution {
public:
    int dp[71][71][71];
    int dx[3] = {-1,0,1};
    int solve(int i, int j1, int j2, vector<vector<int>>&a){
        if(i>=a.size() || j1<0 || j2<0 || j1>=a[0].size() || j2>=a[0].size()){
            return 0;
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int ans = 0;
        for(int x = 0;x<3;x++){
            for(int y = 0 ;y<3;y++){
                ans = max(ans,solve(i+1,j1+dx[x],j2+dx[y],a));
            }
        }
        if(j1==j2){
            ans+=a[i][j1];
        }
        else{
            ans+=a[i][j1] + a[i][j2];
        }
        return dp[i][j1][j2]  = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));

        return solve(0,0,m-1,grid);
    }
};