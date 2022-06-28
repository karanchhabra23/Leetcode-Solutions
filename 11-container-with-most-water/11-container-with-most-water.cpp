class Solution {
public:
    int maxArea(vector<int>& a) {
        int ans = 0;
        int n = a.size();
        int i = 0;
        int j = n-1;
        
        while(i<j){
            int x = (j-i)*(min(a[j],a[i]));
            ans = max(ans,x);
            
            if(a[j]>a[i]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
        
    }
};