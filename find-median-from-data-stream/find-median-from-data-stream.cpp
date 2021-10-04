class MedianFinder {
public:
    priority_queue<int> mx;
    priority_queue<int,vector<int>,greater<int>> mn;
    
    double prev = INT_MIN;
    
    MedianFinder() { }
    
    void addNum(int num) {
        int sizeX = mx.size();
        int sizeN = mn.size();
        
        if(sizeX > sizeN){
            if(num < prev){
                int top = mx.top();
                mx.pop();
                
                mn.push(top);
                mx.push(num);
            }else{
                mn.push(num);
            }
            prev = (mx.top() + mn.top())/2.0;
        }else if(sizeX < sizeN){
            if(prev < num){
                int top = mn.top();
                mn.pop();
                
                mx.push(top);
                mn.push(num);
            }else{
                mx.push(num);
            }
            prev = (mn.top() + mx.top())/2.0;
        }else{
            if(num < prev){
                mx.push(num);
                prev = mx.top();
            }else{
                mn.push(num);
                prev = mn.top();
            }
        }
    }
    
    double findMedian() {
        return prev == INT_MIN? 0 : prev;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */