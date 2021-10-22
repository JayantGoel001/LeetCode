class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        for(auto it : nums){
            if(it <= min1){
                min1 = it;
            }else if(it <= min2){
                min2 = it;
            }else{
                return true;
            }
        }
        return false;
    }
};