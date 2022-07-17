class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int>q;
        vector<int>ans;
        for(int i = 0 ;i<a.size();i++){
            if(!q.empty() && q.front() == i-k){
                q.pop_front();
            }
            while(!q.empty() && a[q.back()]<a[i]){
                q.pop_back();
            }
            q.push_back(i);
            if(i>=k-1){
                ans.push_back(a[q.front()]);
            }
        }
        return ans;
    }
};