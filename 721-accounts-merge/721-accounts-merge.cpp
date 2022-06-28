class Solution {
public:
        unordered_map<string,string>naam;
        unordered_map<string,string>baap;
        map<string,set<string>>group;
    string find(string &a){
        if(baap[a]==a){
            return a;
        }
        return baap[a] = find(baap[a]);
    }
    void Union(string &a, string &b){
        a = find(a);
        b = find(b);
        
        if(a!=b){
            baap[b] = a;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {

        for(int i = 0;i<a.size();i++){
            for(int j =1;j<a[i].size();j++){
                baap[a[i][j]] = a[i][j];
                naam[a[i][j]] = a[i][0];
            }
        }
        for(int i = 0;i<a.size();i++){
            // string p  = find(a[i][1]);
            for(int j = 1;j<a[i].size();j++){
                Union(a[i][1],a[i][j]);
            }
        }
        for(int i = 0;i<a.size();i++){
            for(int j = 1;j<a[i].size();j++){
                group[find(a[i][j])].insert(a[i][j]);
            }
        }
        
        
        vector<vector<string>>s;
        
        for(auto &it:group){
            vector<string>temp;
            string i = *(it.second.begin());
            temp.push_back(naam[i]);
            
            for(auto &x:it.second){
                temp.push_back(x);
            }
            s.push_back(temp);
        }
        return s;
        
        
    }
};