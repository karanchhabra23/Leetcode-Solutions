class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        int m[26] = {0};
        for(auto &it:s){
            m[it-'a']++;
        }
        vector<int>v;
        unordered_set<int>st;
        for(auto it:m){
            if(it!=0)
            v.push_back(it);
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i = 0 ;i<v.size();i++){
            if(!st.count(v[i])){
                st.insert(v[i]);
            }
            else{
                while(st.count(v[i])){
                    v[i]--;
                    ans++;
                }
                if(v[i])st.insert(v[i]);
            }
        }
        return ans;
    }
};