class MinStack {
public:
    stack<int> st;
    stack<int> minStack;
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        int mini = INT_MAX;
        if(!minStack.empty()){
            mini = minStack.top();
        }
        if(mini >= val){
            minStack.push(val);
        }
    }
    
    void pop() {
        int mini = INT_MAX;
        if(!st.empty()){
            mini = st.top();
            st.pop();
        }
        if(!minStack.empty()){
            if(mini == minStack.top()){
                minStack.pop();
            }
        }
    }
    
    int top() {
        if(!st.empty()){
            int mini = st.top();
            return mini;
        }
        return -1;
    }
    
    int getMin() {
        if(!minStack.empty()){
            int mini = minStack.top();
            return mini;
        }
        return INT_MIN;
    }
};