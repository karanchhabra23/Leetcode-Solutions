class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int count = 0;
        for(auto &i:s){
            if(i=='('){
                st.push(i);
            }
            else{
                if(st.empty()){
                    st.push(i);
                }
                else if(st.top() == '('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        return st.size();
    }
};