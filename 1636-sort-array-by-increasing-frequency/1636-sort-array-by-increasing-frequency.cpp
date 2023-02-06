class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> mp(201, 0);
        for(auto it : nums){
            mp[it + 100]++;
        }
        sort(nums.begin(), nums.end(), [&](const int a, const int b) -> bool{
            if(mp[a + 100] == mp[b + 100]){
                return a > b;
            }
            return mp[a + 100] < mp[b + 100];
        });
        return nums;
    }
};