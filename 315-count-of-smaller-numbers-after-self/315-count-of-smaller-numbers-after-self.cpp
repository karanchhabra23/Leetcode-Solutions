class Solution {
public:
    const int N = 1e5 + 10;
    long long bit[100011] = {0};
    
    
    void update(int i, int val){
        while(i<=N){
            bit[i]+=val;
            i+=(i & (-i));
        }
    }
    int sum(int i){
        int ans = 0;
        while(i){
            ans+=bit[i];
            i-= (i & (-i));
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        
        for(int i =  n-1;i>=0;i--){
            nums[i]+= 1e4 + 1;
            int x = sum(nums[i]-1);
            ans[i] = x;
            update(nums[i],1);
        }
        return ans;
    }
};