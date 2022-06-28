class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
            unordered_set<string>st;
            int n = start.size();
            queue<string>q;
            vector<char>v = {'A','C','G','T'};
            for(auto &it:bank){
                st.insert(it);
            }

            if(st.find(end)==st.end()){
                return -1;
            }
            q.push(start);
            int len = 0;
            while(!q.empty()){
                int sz = q.size();
                len++;
                for(int z = 0;z<sz;z++){
                    string curr  = q.front();
                    q.pop();
                    for(int i = 0;i<8;i++){
                        char c = curr[i];

                        for(auto &ch:v){
                            if(ch!=c){
                                curr[i] = ch;

                                if(curr==end){
                                    return len;
                                }
                                if(st.find(curr)==st.end()){
                                    continue;
                                }
                                q.push(curr);
                                st.erase(curr);  
                            }                    
                        }
                        curr[i] = c;

                    }
                }

            }
            return -1;

    }
};