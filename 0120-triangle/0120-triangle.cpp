class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j, vector<vector<int>>&a){
        if(j>i){
            return 1e7;
        }
        if(i==a.size()-1){
            return a[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = a[i][j];
        // if(j==0){
            ans+= min(solve(i+1,j,a),solve(i+1,j+1,a));
        // }
        return dp[i][j] = ans;
        
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,0,triangle);
    }
};