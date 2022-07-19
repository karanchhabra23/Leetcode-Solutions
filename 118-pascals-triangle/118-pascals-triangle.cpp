class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>v;
        v.push_back({1});
        for(int i = 1;i<n;i++){
            vector<int>temp(i+1);
            temp[0] = 1;
            for(int j = 1;j<i;j++){
                temp[j] = v[i-1][j] + v[i-1][j-1];
            }
            temp[i] = 1;
            v.push_back(temp);
        }
        return v;
    }
};