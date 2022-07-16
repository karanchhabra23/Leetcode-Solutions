class Solution {
public:
    string par;
    void solve(int i, string &s,unordered_set<string>&st, vector<string>&ans){
        if(i==par.size()){
           ans.push_back(s);
            return;
        }
//         if(st.count(par.substr(i,par.size()-i))){
            
//             if(s.size())s+=" ";
            
//             s+=par.substr(i,par.size()-i);
//             ans.push_back(s);
//             return;
//         }
        if(i>=par.size()){
            return;
        }
        
        for(int x = 1;x<=par.size()-i;x++){
            if(st.count(par.substr(i,x))){
                string temp = s;
                if(temp.size())temp+= " ";
                
                temp+= par.substr(i,x);
                
                solve(i+x,temp,st,ans);
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        unordered_set<string>st;
        for(auto &it:wordDict){
            st.insert(it);
        }
        string x = "";
        par = s;
        
        solve(0,x,st,ans);
        return ans;
    }
};