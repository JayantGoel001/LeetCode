class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        int sum = 0;
        for(auto it : mp){
            sum += (it.second == 1) ? it.first : 0;
        }
        return sum;
    }
};