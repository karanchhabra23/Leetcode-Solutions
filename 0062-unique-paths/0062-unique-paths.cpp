class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, int n , int m){
        if(i==n-1 && j == m-1)return 1;
        if(i>=n || j>=m )return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = solve(i+1,j,n,m) + solve(i,j+1,n,m);
    }
    int uniquePaths(int m, int n) {
        dp.resize(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n);
    }
};