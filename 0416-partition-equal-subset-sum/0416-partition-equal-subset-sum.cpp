class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i= 0;i<n;i++)sum+=arr[i];
        if(sum&1)return false;
        int k = sum/2;
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i = 0;i<=n;i++){
            for(int j = 0 ;j<=k;j++){
                dp[i][0]=1;
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=k;j++){
                if(arr[i-1]<=j){
                    dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]]; 
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][k]>0;
    }
};