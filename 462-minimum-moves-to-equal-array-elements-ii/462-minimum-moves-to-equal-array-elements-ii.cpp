class Solution {
public:
    int minMoves2(vector<int>& a) {
        
        sort(a.begin(),a.end());
        int n = a.size();
        if(n==1){return 0;}
        if(n==2){
            return a[1]-a[0];
        }

        int mid = a[n/2];
        long long sum = 0;
        for(int i = 0;i<n;i++){
            sum+= abs(a[i]-mid);
        }
        return sum;

    }
};