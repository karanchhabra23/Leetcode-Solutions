class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        int n = beginWord.size();
        queue<string>q;
        
        for(auto &it:wordList){
            st.insert(it);
        }
        
        if(st.find(endWord)==st.end()){
            return 0;
        }
        q.push(beginWord);
        int len = 0;
        while(!q.empty()){
            int sz = q.size();
            len++;
            for(int z = 0;z<sz;z++){
                string curr  = q.front();
                q.pop();
                for(int i = 0;i<n;i++){
                    char c = curr[i];

                    for(char ch = 'a' ; ch<='z' ; ch++){
                        if(ch!=c){
                            curr[i] = ch;

                            if(curr==endWord){
                                return len+1;
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
        return 0;
        
        
    }
};