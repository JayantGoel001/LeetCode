class StockSpanner {
public:
    int i = 0;
    stack<int> st;
    vector<int> v;
    StockSpanner() {}
    
    int next(int price) {
        while(!st.empty() && v[st.top()] <= price){
            st.pop();
        }
        int top = -1;
        if(!st.empty()){
            top = st.top();
        }
        
        st.push(i);
        v.push_back(price);
        return i++ - top;
    }
};