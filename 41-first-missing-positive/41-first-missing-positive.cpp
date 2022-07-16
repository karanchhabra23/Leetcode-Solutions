class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        int i = 0;
        while(i<n){
            if(a[i]<=n && a[i]>0){
                if(a[a[i]-1]!=a[i]){
                    swap(a[a[i]-1],a[i]);
                }
                else{
                    i++;
                }
            }
            else{
                i++;   
            }
        }
        int ans;
        for(int i =0 ;i<n;i++){
            if(a[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};