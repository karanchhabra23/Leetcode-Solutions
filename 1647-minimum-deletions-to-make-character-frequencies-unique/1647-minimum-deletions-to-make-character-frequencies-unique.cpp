class Solution {
public:
    int minDeletions(string st) {
        int n = st.size();
        int m[26] = {0};
        for(auto &it:st){
            m[it-'a']++;
        }
        vector<int>v;
        unordered_set<int>s;
        for(auto it:m){
            if(it!=0)
            v.push_back(it);
        }
        //
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i = 0 ;i<v.size();i++){
            if(!s.count(v[i])){
                s.insert(v[i]);
            }
            else{
                while(s.count(v[i])){
                    v[i]--;
                    ans++;
                }
                if(v[i])s.insert(v[i]);
            }
        }
        return ans;
    }
};