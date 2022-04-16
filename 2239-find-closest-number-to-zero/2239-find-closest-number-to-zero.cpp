class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int value = INT_MAX;
        for(auto it : nums){
            if(abs(it) < abs(value)){
                value = it;
            }else if(abs(it) == abs(value)){
                value = max(value,it);
            }
        }
        return value;
    }
};