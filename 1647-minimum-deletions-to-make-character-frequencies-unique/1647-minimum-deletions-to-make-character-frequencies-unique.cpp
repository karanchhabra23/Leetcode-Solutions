class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        int m[26] = {0};
        for(auto &it:s){
            m[it-'a']++;
        }
        unordered_map<int,int>mp;
        int maxi = 0;
        set<int>st;
        for(int i = 0;i<=n;i++){
            st.insert(i);
        }
        for(char c = 'a';c<='z';c++){
            mp[m[c-'a']]++;
            maxi = max(maxi,mp[m[c-'a']]);
        }
        // mp kehri frequency kinni vaar aa chukki
        // _print(mp);
        vector<int>v;
        for(auto &it:mp){
            if(it.first==0){
                continue;
            }
            if(it.second>1){
                for(int i = 0;i<it.second-1;i++){
                    v.push_back(it.first);
                }
                st.erase(it.first);
            }
            else if(it.second==1){
                st.erase(it.first);
            }
        }
        // _print(v);
        // _print(st);
        int ans = 0;
        st.insert(0);
        for(auto &i:v){
            auto it = --st.upper_bound(i);
            int x = *it;
            ans+=(i-x);
            if(x!=0){
                st.erase(it);
            }
        }
        return ans;


    }
};