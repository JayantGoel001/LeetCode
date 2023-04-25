class SmallestInfiniteSet {
public:
    set<int> st;
    int cur = 1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int answer;
        if(!st.empty()){
            answer = *st.begin();
            st.erase(answer);
        }else{
            answer = cur;
            cur++;
        }
        return answer;
    }
    
    void addBack(int num) {
        if(cur > num && st.find(num) == st.end()){
            st.insert(num);
        }
    }
};
