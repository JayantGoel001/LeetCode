class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int nPos = -1;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i] < 0){
                nPos = i;
            }
            nums[i] *= nums[i];
        }
        vector<int> v;
        int i = nPos;
        int j = nPos + 1;
        
        while(i>=0 && j<n){
            if(nums[i] <= nums[j]){
                v.push_back(nums[i--]);
            }else{
                v.push_back(nums[j++]);
            }
        }
        
        while(i >= 0){
            v.push_back(nums[i--]);
        }
        while(j < n){
            v.push_back(nums[j++]);
        }
        return v;
    }
};