class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return a > b;
        });
        vector<int> v;
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        int lsum = 0;
        
        for(auto it : nums){
            lsum += it;
            sum -=it;
            
            v.push_back(it);
            
            if(lsum > sum){
                break;
            }
            
        }
        return v;
    }
};