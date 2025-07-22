class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi = 0;
        int sum = 0;
        int j = 0;
        
        for(int i=0;i<nums.size();i++){
            while(mp[nums[i]] != 0 && j < i){
                sum -= nums[j];
                mp[nums[j]]--;
                j++;
            }
            sum += nums[i];
            mp[nums[i]]++;
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};