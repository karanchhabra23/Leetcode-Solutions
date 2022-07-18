class Solution {
public:
    const int mod = 1e9 + 7;
    typedef long long ll;
    ll dp[1010][1010];
    ll solve(int n,int k){
        if(n==2){
            if(k==0 || k==1){
                return 1;
            }
            return 0;
        }
        if(k<0 || k>(n*(n-1))/2)return 0;
        if(k==0 || k== (n*(n-1))/2)return 1;
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        ll ans =0 ;
        ans+= solve(n,k-1);
        ans%=mod;
        ans+=solve(n-1,k);
        ans%=mod;
        if(k>=n)
        ans-=solve(n-1,k-n);
        
        return dp[n][k] = ans%mod;
        
    }
    int kInversePairs(int n, int k) {
        
        memset(dp,-1,sizeof(dp));
        return (solve(n,k)+mod)%mod;
        
    }
};