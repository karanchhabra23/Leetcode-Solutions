class Solution {
public:
    int minMoves2(vector<int>& a) {
        
        sort(a.begin(),a.end());
        int n = a.size();
        if(n==1){return 0;}
        if(n==2){
            return a[1]-a[0];
        }
        if(n&1){
            int mid = a[n/2];
            long long sum = 0;
            for(int i = 0;i<n;i++){
                sum+= abs(a[i]-mid);
            }
            return sum;
        }
        else {
            int mid1 = a[n/2];
            int mid2 = a[n/2 + 1];
            long long sum1=0, sum2  = 0;
            for(int i = 0;i<n;i++){
                sum1+=abs(a[i]-mid1);
                sum2+=abs(a[i]-mid2);
            }
            return min(sum1,sum2);
        }
    }
};