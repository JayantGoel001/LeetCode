class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k == 0){
            return nums[0];
        }
        if(k == 1 && nums.size() == 1){
            return -1;
        }
        if(k%2 && nums.size() == 1){
            return -1;
        }
        int maxi = 0;
        for(int i=0;i<min((int)nums.size(),k-1);i++){
            maxi = max(maxi,nums[i]);
        }
        if(k < nums.size()){
            maxi = max(maxi,nums[k]);
        }
        return maxi;
    }
};