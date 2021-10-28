class CustomStack {
public:
    stack<int> st;
    vector<int> v;
    
    int maxSize;
    
    
    CustomStack(int maxSize) {
        v.resize(maxSize,0);
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(st.size() < maxSize){
            st.push(x);
        }
    }
    
    int pop() {
        if(!st.empty()){
            int i = st.size()-1;
            if(i > 0){
                v[i-1] += v[i];
            }
            int top = st.top() + v[i];
            v[i] = 0;
            st.pop();
            return top;
        }else{
            return -1;
        }
    }
    int min(int a,int b){
        return a > b ? b : a;
    }
    void increment(int k, int val) {
        int i = min(k,st.size())-1;
        if(i>=0){
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */