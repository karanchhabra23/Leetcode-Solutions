class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        stack<int>st;
        vector<int>v(n);
        for(int i = 2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=a[i%n]){
                st.pop();
            }
            if(i<n){
                if(st.empty())
                    v[i] = -1;
                else v[i] = st.top();
            }
            st.push(a[i%n]);

        }
        return v;
        
    }
};