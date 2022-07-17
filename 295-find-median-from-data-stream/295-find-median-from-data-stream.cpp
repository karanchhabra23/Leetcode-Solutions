class MedianFinder {
public:
    bool even = true;
    priority_queue<int>q1;
    priority_queue<int,vector<int>,greater<int>>q2;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        // q2.push(num);
        // sz++;
        // int req;
        // req = sz/2 + 1;
        // while(q1.size()<req){
        //     q1.push(q2.top());
        //     q2.pop();
        // }
        // cout<<q1.top()<<endl;
        if(even){
        q2.push(num);
        q1.push(q2.top());
        q2.pop();
        }
        else{
            q1.push(num);
            q2.push(q1.top());
            q1.pop();
        }
        even = !even;
        
    }
    
    double findMedian() {
        if(even){
            double x = q1.top() + q2.top();
            x/=2.0;
            return x;
        }
        else{
            return q1.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */