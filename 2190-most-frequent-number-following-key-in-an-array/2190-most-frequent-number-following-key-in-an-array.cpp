class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == key && i+1<nums.size()){
                mp[nums[i+1]]++;
            }
        }
        int maxi = 0;
        for(auto it : mp){
            if(mp[maxi] < it.second){
                maxi = it.first;
            }
        }
        return maxi;
    }
};