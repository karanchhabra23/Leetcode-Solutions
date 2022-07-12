class Solution {
public:
    typedef long long int ll;
    ll cnt(ll mid, vector<int> &a){
        ll ans = 0;
        for(auto &it:a){
            ans+= it/mid + (it%mid>0);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& a, int k) {
        int n = a.size();
        ll ans;
        ll hi = 1e9;
        ll lo = 1;
        while(hi>=lo){
            ll mid = (hi+lo)/2;
            ll x = cnt(mid,a);
            if(x<=k){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1; 
            }
        }
        return ans;
    }
};