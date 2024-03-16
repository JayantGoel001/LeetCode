class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        int count = 0;
        int size = nums.size();
        int maxi = 0;
        for(int i=0;i<size;i++){
            count += nums[i] == 1 ? 1 : -1;
            if(mp.count(count)==0){
                mp[count] = i; 
            }else{
                maxi = max(maxi,i - mp[count]);
            }
        }
        return maxi;
    }
};