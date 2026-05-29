class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 37;
        for (int num : nums) {
            int dig = 0;
            while (num) {
                dig += num % 10;
                num /= 10;
            }
            ans = min(ans, dig);
        }
        return ans;
    }
};