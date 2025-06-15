class Solution {
public:
    int maxDiff(int num) {
        auto replace = [](string& s, char x, char y) {
            for (char& digit : s) {
                if (digit == x) {
                    digit = y;
                }
            }
        };

        string min_num = to_string(num);
        string max_num = to_string(num);
        // Find a high position and replace it with 9.
        for (char digit : max_num) {
            if (digit != '9') {
                replace(max_num, digit, '9');
                break;
            }
        }

        // Replace the most significant bit with 1
        // Or find a high-order digit that is not equal to the highest digit and
        // replace it with 0.
        for (int i = 0; i < min_num.size(); ++i) {
            char digit = min_num[i];
            if (i == 0) {
                if (digit != '1') {
                    replace(min_num, digit, '1');
                    break;
                }
            } else {
                if (digit != '0' && digit != min_num[0]) {
                    replace(min_num, digit, '0');
                    break;
                }
            }
        }

        return stoi(max_num) - stoi(min_num);
    }
};