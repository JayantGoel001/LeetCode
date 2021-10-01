class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        
        sort(nums.begin(),nums.end());
        
        int size = nums.size();
        for(int i=0;i<size;i++){
            
            int j = i + 1;
            int k = size-1;
            
            while(j<k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    v.push_back({nums[i],nums[j],nums[k]});
                    
                    while(j < k && nums[j] == nums[j+1]){
                        j++;
                    }
                    while(j < k && nums[k] == nums[k-1]){
                        k--;
                    }
                    j++;
                    k--;
                }else if(nums[j] + nums[k] + nums[i] > 0){
                    k--;
                }else{
                    j++;
                }
                
            }
            while(i + 1< size && nums[i] == nums[i+1]){
                i++;
            }
        }
        return v;
    }
};