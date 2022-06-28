class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>dead;
        for(auto &it:deadends){
            dead.insert(it);
        }
        if(dead.count(target))return -1;
        if(dead.count("0000"))return -1;
        unordered_set<string>vis;
        queue<string>q;
        q.push("0000");
        vis.insert("0000");
        int res = 0;
        while(!q.empty()){
            
            int sz = q.size();
            while(sz--){
                string s = q.front();
                if(s==target){
                    return res;
                }
                q.pop();
                for(int i = 0;i<4;i++){
                    char c = s[i];
                    if(c=='9'){
                        s[i] = '8';
                        if(!dead.count(s) && !vis.count(s)){
                            q.push(s);
                            vis.insert(s);
                        }
                        s[i] = '0';
                        if(!dead.count(s) && !vis.count(s)){
                            q.push(s);
                            vis.insert(s);
                        }
                    }
                    else if(c=='0'){
                        s[i] = '1';
                        if(!dead.count(s) && !vis.count(s)){
                            q.push(s);
                            vis.insert(s);
                        }
                        s[i] = '9';
                        if(!dead.count(s) && !vis.count(s)){
                            q.push(s);
                            vis.insert(s);
                        }
                    }
                    else{
                        s[i]++;
                        if(!dead.count(s) && !vis.count(s)){
                            q.push(s);
                            vis.insert(s);
                        }
                        s[i]-=2;
                        if(!dead.count(s) && !vis.count(s)){
                            q.push(s);
                            vis.insert(s);
                        }
                    }
                    s[i] = c;
                }
                
            }
            res++;
        }
        return -1;
    }
};