class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        int r = sum % 9;
        string ans(sum / 9, '9');
        if (r > 0) {
            ans.push_back('0' + r);
        }
        ans.append(num - (int)ans.size(), '0');
        return ans;
    }
};