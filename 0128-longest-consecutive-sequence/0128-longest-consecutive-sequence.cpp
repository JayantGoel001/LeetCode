class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        
        int maxi = 0;
        for(auto num : nums) {
            if (st.find(num - 1) == st.end()) {
                int x = num + 1;
                while(st.find(x) != st.end()) x++;
                
                maxi = max(maxi, x - num);
            }
        }
        
        return maxi;
    }
};