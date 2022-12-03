class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, int n , int m,vector<vector<int>>&a){
        if(i>=n || j>=m || a[i][j]==1)return 0;

        if(i==n-1 && j == m-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = solve(i+1,j,n,m,a) + solve(i,j+1,n,m,a);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        if(a[0][0]==1|| a[n-1][m-1]==1)return 0;
        return solve(0,0,n,m,a);
    }
};