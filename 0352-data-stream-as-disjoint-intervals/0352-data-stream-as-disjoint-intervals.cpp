class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        int left = -1;
        int right = -1;
        
        vector<vector<int>> v;
        for(auto it : st){
            if(left == -1){
                left = it;
                right = it;
            }else{
                if(it == right + 1){
                    right++;
                }else{
                    v.push_back({left, right});
                    left = it;
                    right = it;
                }
            }
        }
        v.push_back({left, right});
        return v;
    }
};