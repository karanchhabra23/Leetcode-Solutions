class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>q;
    int c;
    KthLargest(int k, vector<int>& nums) {
        c = k;
        for(auto &it:nums){
            q.push(it);
            if(q.size()>c)q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size()>c){
            q.pop();
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */