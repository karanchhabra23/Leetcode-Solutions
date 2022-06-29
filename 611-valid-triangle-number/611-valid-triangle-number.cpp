class Solution {
public:
    int triangleNumber(vector<int>& a) {
        int n =a.size();
        int ans = 0;
        sort(a.begin(),a.end());
        for(int i = n-1;i>=2;i--){
            int j = 0;
            int k = i-1;
            while(k>j){
                if(a[j]+a[k]>a[i]){
                    ans+=k-j;
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
            
 
    }
};