class MinStack {
public:
    stack<long> st;
    long mini = INT_MAX;
    MinStack() {}
    
    void push(int val) {
        st.push((long)val - mini);
        mini = min(mini,(long)val);
    }
    
    void pop() {
        mini = max(mini,mini - st.top());
        st.pop();
    }
    
    int top() {
        return max(st.top(),0L) + mini;
    }
    
    int getMin() {
        return mini;
    }
};