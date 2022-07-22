class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    int front;
    MyQueue() {}
    
    void push(int x) {
        if(s1.empty()){
            front = x;
        }
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }
        return front;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};