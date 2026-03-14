class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        for(auto it : nums) {
            if (mp[k - it] > 0) {
                count++;
                mp[k - it]--;
            } else {
                mp[it]++;
            }
        }

        return count;
    }
};