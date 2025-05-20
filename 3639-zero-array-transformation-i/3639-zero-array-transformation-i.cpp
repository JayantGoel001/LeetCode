class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> qSum(nums.size() + 1, 0);

        for(auto it : queries) {
            qSum[it[0]]++;
            qSum[it[1] + 1]--;
        }

        for(int i=1;i<=nums.size();i++) {
            qSum[i] += qSum[i - 1];
        }
        bool zero = true;

        for(int i=0;i<nums.size();i++) {
            zero &= (nums[i] - qSum[i]) <= 0;
        }

        return zero;
    }
};