#define pii pair<int,int>
class StockSpanner {
public:
    int count;
    stack<pii> st;
    StockSpanner() :count(0) {}
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }
        count++;
        int span = count - (st.empty() ? 0 : st.top().second);
        st.push({price, count});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */