class SmallestInfiniteSet {
public:
    int minElement;
    set<int> st;
    SmallestInfiniteSet() : minElement(1) {
        
    }
    
    int popSmallest() {
        if (!st.empty() && *st.begin() < minElement) {
            int top = *st.begin();
            st.erase(top);
            return top;
        }
        return minElement++;
    }
    
    void addBack(int num) {
        if (st.find(num) != st.end() || minElement <= num) return;
        
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */