class MinStack {
private:
    stack<int> st;
    stack<int> mst;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(!mst.empty()){
            mst.push(min(mst.top(),val));
        }else{
            mst.push(val);
        }
    }
    
    void pop() {
        st.pop();
        mst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
    }
};