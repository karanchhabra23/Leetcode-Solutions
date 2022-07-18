class Solution {
public:
    const int mod = 1e9 + 7;
    typedef long long ll;
    ll dp[1010][1010];
    int kInversePairs(int n, int k) {
        
        // memset(dp,-1,sizeof(dp));
        // return solve(n,k);
        if(n==1){
            return k==0;
        }
        dp[2][0] = 1;
        dp[2][1] = 1;
        for(int i = 3;i<=n;i++){
            dp[i][0]  = 1;
            for(int j = 1;j<=k;j++){
                if(j>(i)*(i-1)/2){
                    continue;
                }
                dp[i][j] += dp[i][j-1];
                dp[i][j] += dp[i-1][j] ;
                if(j>=i){
                    dp[i][j] +=  mod - dp[i-1][j-i];
                }
                dp[i][j]+=mod;
                dp[i][j]%=mod;
            }
        }
        return dp[n][k];
        
    }
};