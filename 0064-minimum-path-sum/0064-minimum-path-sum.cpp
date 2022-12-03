class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, int n , int m,vector<vector<int>>&a){
        if(i>=n || j>=m)return 1e7 ;

        if(i==n-1 && j == m-1)return a[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = min(solve(i+1,j,n,m,a) , solve(i,j+1,n,m,a)) + a[i][j];
    }
    int minPathSum(vector<vector<int>>& a) {
         int n = a.size();
        int m = a[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,a);
    }
};