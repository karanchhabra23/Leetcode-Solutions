class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>in(n+1,0),out(n+1,0);
        for(auto &it:trust){
            in[it[0]]++;
            out[it[1]]++;
        }
        for(int i = 1;i<=n;i++){
            if(in[i]==0 && out[i]==n-1){
                return i;
            }
            // if(in[i]==0)return i;
        }
        return -1;
    }
};