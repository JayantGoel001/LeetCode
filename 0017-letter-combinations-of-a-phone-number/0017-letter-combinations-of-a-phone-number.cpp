class Solution {
public:
    void combination(string &digits, vector<string> &res, int index, vector<vector<char>> &phone, string &str) {
        if (index == digits.size()) {
            res.push_back(str);
            return;
        }

        for(auto it : phone[digits[index] - '0']) {
            str.push_back(it);
            combination(digits, res, index+1, phone, str);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> phone(10);
        phone[2] = {'a', 'b', 'c'};
        phone[3] = {'d', 'e', 'f'};
        phone[4] = {'g', 'h', 'i'};
        phone[5] = {'j', 'k', 'l'};
        phone[6] = {'m', 'n', 'o'};
        phone[7] = {'p', 'q', 'r', 's'};
        phone[8] = {'t', 'u', 'v'};
        phone[9] = {'w', 'x', 'y', 'z'};

        vector<string> res;
        string str = "";
        combination(digits, res, 0, phone, str);

        return res;
    }
};