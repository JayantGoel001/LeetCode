class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> v;
        int size = nums.size();
        for(int i=0;i<size;i++){
            int j = i+1;
            int k = size-1;
            
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    v.push_back({nums[i],nums[j],nums[k]});
                    
                    while(j+1 <= k && nums[j] == nums[j+1]){
                        j++;
                    }
                    j++;
                    while(j <= k-1 && nums[k] == nums[k-1]){
                        k--;
                    }
                    k--;
                }else if(nums[j] + nums[k] < -nums[i]){
                    j++;
                }else{
                    k--;
                }
            }
            
            while(i+1 < size && nums[i] ==nums[i+1]){
                i++;
            }
        }
        return v;
    }
};