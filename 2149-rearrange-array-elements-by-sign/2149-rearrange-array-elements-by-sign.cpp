class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        
        int i = 0;
        int j = 1;
        vector<int> v(n);
        while(k < n){
            if(nums[k] > 0){
                v[i] = nums[k];
                i+=2;
            }else{
                v[j] = nums[k];
                j+=2;
            }
            k++;
        }
        return v;
    }
};