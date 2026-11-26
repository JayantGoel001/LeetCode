class Solution {
public:
    bool canAliceWin(int n) {
        int k = (21 - sqrt(441 - 8 * n)) / 2;
        return k % 2 == 1;
    }
};