class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> st;
        for(auto it : points){
            st.insert(it[0]);
        }
        int maxi = 0;

        int prev = INT_MAX;
        for(auto it : st){
            maxi = max(maxi, it - prev);
            prev = it;
        }
        
        return maxi;
    }
};