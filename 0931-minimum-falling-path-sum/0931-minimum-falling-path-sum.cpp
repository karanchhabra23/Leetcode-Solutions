class Solution {
public:
    vector<vector<int>>dp;
    
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        for(int i = 0 ;i<m;i++){
            dp[0][i] = a[0][i];
        }
        for(int i = 1;i<n;i++){
            for(int j = 0;j<m;j++){
                if(j==0){
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j+1]);
                }   
                else if(j==m-1){
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]);
                }
                else{
                    dp[i][j] = min({dp[i-1][j],dp[i-1][j+1],dp[i-1][j-1]});
                }
                dp[i][j]+=a[i][j];
            }
        }
        int ans = 1e8 ;
        for(int i = 0;i<m;i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};