class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit[32] = {0};
        for(auto &it:nums){
            for(int i = 0;i<32;i++){
                if(1<<i & it){
                    bit[i]++;
                }
            }
        }
        int ans = 0 ;
        for(int i = 0;i<32;i++){
            if(bit[i]%3==1){
                ans|= 1<<i;
            }
        }
        return ans;
    }
};