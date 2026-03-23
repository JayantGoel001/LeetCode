class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int minElement;
    unordered_set<int> st;
    SmallestInfiniteSet() : minElement(1) {
        
    }
    
    int popSmallest() {
        if (!pq.empty() && pq.top() < minElement) {
            int top = pq.top();
            pq.pop();

            st.erase(top);
            return top;
        }
        return minElement++;
    }
    
    void addBack(int num) {
        if (st.find(num) != st.end() || minElement <= num) return;
        
        pq.push(num);
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */