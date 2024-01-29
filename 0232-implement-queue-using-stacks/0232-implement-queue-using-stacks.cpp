class MyQueue {
public:
    stack<int> st1,st2;
    int front = 0;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st1.empty()){
            front = x;
        }
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int top = st2.top();
        st2.pop();
        return top;
    }
    
    int peek() {
        if(!st2.empty()){
            return st2.top();
        }
        return front;
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};