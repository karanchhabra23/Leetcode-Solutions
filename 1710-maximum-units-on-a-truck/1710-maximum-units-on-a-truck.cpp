class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& a, int x) {
        int ans = 0;
        sort(a.begin(),a.end(),cmp);
        for(int i = 0;i<a.size();i++){
            if(a[i][0]<=x){
                x-=a[i][0];
                ans+=a[i][0]*a[i][1];
            }
            else{
                ans+=x*a[i][1];
                x = 0;
            }
            
            if(x==0){
                return ans;
            }
        }
        return ans;
    }
};