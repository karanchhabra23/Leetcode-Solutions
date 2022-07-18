class Solution {
public:
    const int mod = 1e9 + 7;
    typedef long long ll;
    // ll dp[1010][1010];
    int kInversePairs(int n, int k) {
        
        // memset(dp,-1,sizeof(dp));
        // return solve(n,k);
        if(n==1){
            return k==0;
        }
        if(k==0){
            return 1;
        }
        vector<ll> curr(k+1,0),past(k+1,0);
        // int past[k+1];
        past[0] = 1;
        past[1] = 1;
        curr[0] = 1;
        curr[1] = 1;
        for(int i = 3;i<=n;i++){
            curr[0]  = 1;
            for(int j = 1;j<=min(k,i*(i-1)/2);j++){
                // if(j>(i)*(i-1)/2){
                //     continue;
                // }
                curr[j] = curr[j-1];
                curr[j] += past[j] ;
                if(j>=i){
                    curr[j] +=  mod - past[j-i];
                }
                curr[j]+=mod;
                curr[j]%=mod;
            }
            past = curr;
        }
        return past[k];
        
    }
};