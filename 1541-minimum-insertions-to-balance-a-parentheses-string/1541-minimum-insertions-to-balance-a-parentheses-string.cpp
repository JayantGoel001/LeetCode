class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int leftCount = 0;
        int length = s.size();
        int index = 0;
        while (index < length) {
            char c = s[index];
            if (c == '(') {
                leftCount++;
                index++;
            } else {
                if (leftCount > 0) {
                    leftCount--;
                } else {
                    insertions++;
                }
                if (index < length - 1 && s[index + 1] == ')') {
                    index += 2;
                } else {
                    insertions++;
                    index++;
                }
            }
        }
        insertions += leftCount * 2;
        return insertions;
    }
};