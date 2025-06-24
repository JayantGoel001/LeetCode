class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            bool flag = false;
            for(int j = 0;j<n;j++){
                if(nums[j] == key && abs(i - j) <= k){
                    flag = true;
                }
            }
            if(flag){
                v.push_back(i);
            }
        }
        return v;
    }
};