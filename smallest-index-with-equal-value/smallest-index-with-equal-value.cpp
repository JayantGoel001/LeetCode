class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int mini = INT_MAX;
        int size = nums.size();
        for(int i=0;i<size;i++){
            if(i%10 == nums[i]){
                mini = min(mini,i);
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};