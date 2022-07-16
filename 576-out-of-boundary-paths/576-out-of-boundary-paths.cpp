class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[51][51][51];
    int solve(int i, int j, int moves, int n, int m){
        if(i>=n || j >=m || i<0 || j<0){
            return 1;
        }
        if(moves==0){
            return 0;
        }
        if(dp[i][j][moves]!=-1){
            return dp[i][j][moves];
        }
        long long ans=0;
        ans+= solve(i-1,j,moves-1,n,m);
        ans+= solve(i,j-1,moves-1,n,m);
        ans+= solve(i+1,j,moves-1,n,m);
        ans+= solve(i,j+1,moves-1,n,m);
        ans%=mod;
        return dp[i][j][moves]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(startRow,startColumn,maxMove,m,n);
    }
};