class Solution {
public:
    int minSwaps(string s) {
        int stackSize = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            // If character is opening bracket, increment the stack size.
            if (ch == '[')
                stackSize++;
            else {
                // If the character is closing bracket, and we have an opening
                // bracket, decrease the stack size.
                if (stackSize > 0) stackSize--;
            }
        }
        return (stackSize + 1) / 2;
    }
};