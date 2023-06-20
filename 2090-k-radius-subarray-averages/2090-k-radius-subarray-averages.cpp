class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> v(nums.size(), 0);
        long long int sum = 0;
        
        for(int i=0;i<nums.size();i++){
            sum += (long long int)nums[i];
            
            if(i < k || (nums.size() - i - 1) < k){
                v[i] = -1;
            }
            if(i >= 2 * k){
                cout<<sum<<" ";
                v[i - k] = sum/(2 * k + 1);
                sum -= nums[i - 2 * k];
            }
        }
        
        return v;
    }
};