class MedianFinder {
public:
    priority_queue<int> mx;
    priority_queue<int,vector<int>,greater<int>> mn;
    
    int i = 0;
    
    MedianFinder() {}
    
    void addNum(int num) {
        if(i%2 == 0){
            mn.push(num);
            mx.push(mn.top());
            mn.pop();
        }else{
            mx.push(num);
            mn.push(mx.top());
            mx.pop();
        }
        i++;
    }
    
    double findMedian() {
        if(i%2 == 0){
            return (mx.top() + mn.top())/2.0;
        }else{
            return mx.top();
        }
    }
};