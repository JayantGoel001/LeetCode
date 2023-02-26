class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi = -1;
        
        unordered_set<int> st;
        for(auto it : nums){
            if(st.find(-it) != st.end()){
                maxi = max(maxi, abs(it));
            }
            st.insert(it);
        }
        return maxi;
    }
};