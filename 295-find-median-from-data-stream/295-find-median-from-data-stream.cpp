class MedianFinder {
public:
    int i = 0;
    priority_queue<double> mx;
    priority_queue<double,vector<double>,greater<double>> mn;
    
    MedianFinder() {}
    
    void addNum(int num) {
        if(i%2 != 0){
            mx.push(num);
            mn.push(mx.top());
            mx.pop();
        }else{
            mn.push(num);
            mx.push(mn.top());
            mn.pop();
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