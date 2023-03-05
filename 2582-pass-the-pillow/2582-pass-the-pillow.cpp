class Solution {
public:
    int passThePillow(int n, int time) {
        int x = time % ((n - 1) * 2) + 1;
        return min(x, 2 * n - x);
    }
};