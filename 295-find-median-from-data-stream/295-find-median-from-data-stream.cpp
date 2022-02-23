class MedianFinder {
public:
    priority_queue<int> pqx;
    priority_queue<int,vector<int>,greater<int>> pqn;
    double prev = INT_MIN;
    
    MedianFinder() {}
    
    void addNum(int num) {
        int sn = pqn.size();
        int sx = pqx.size();
        
        if(sn == sx){
            if(num < prev){
                pqx.push(num);
                prev = pqx.top();
            }else{
                pqn.push(num);
                prev = pqn.top();
            }
        }else if(sn < sx){
            if(num < prev){
                int top = pqx.top();
                pqx.pop();
                
                pqn.push(top);
                pqx.push(num);
            }else{
                pqn.push(num);
            }
            prev = (pqx.top() + pqn.top())/2.0;
        }else{
            if(num < prev){
                pqx.push(num);
            }else{
                int top = pqn.top();
                pqn.pop();
                
                pqx.push(top);
                pqn.push(num);
            }
            prev = (pqx.top() + pqn.top())/2.0;
        }
    }
    
    double findMedian() {
        return prev == INT_MIN ? 0.0 : prev;
    }
};