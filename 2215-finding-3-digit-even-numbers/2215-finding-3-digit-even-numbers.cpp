class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> nums;  // Target even set
        int n = digits.size();
        // Traverse the indices of three digits
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    // Determine whether it meets the condition of the target
                    // even number
                    if (i == j || j == k || i == k) {
                        continue;
                    }
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num >= 100 && num % 2 == 0) {
                        nums.insert(num);
                    }
                }
            }
        }
        // Converted to an array sorted in ascending order
        vector<int> res;
        for (const int num : nums) {
            res.push_back(num);
        }
        sort(res.begin(), res.end());
        return res;
    }
};