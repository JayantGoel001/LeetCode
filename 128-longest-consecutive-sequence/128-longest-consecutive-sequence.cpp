class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        
        for(auto it : nums){
            st.insert(it);
        }
        int maxi = 0;
        int count = 0;
        
        for(auto it : nums){
            if(st.find(it-1) == st.end()){
                int el = it;
                count = 0;
                while(st.find(el) != st.end()){
                    count++;
                    el++;
                }
                maxi = max(maxi,count);
            }
        }
        return maxi;
    }
};