class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int mn1 = INT_MAX, mn2 = INT_MAX, mn3 = INT_MAX;
        int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;

        for (int x : nums) {
            if (x < mn1) {
                mn3 = mn2;
                mn2 = mn1;
                mn1 = x;
            } else if (x < mn2) {
                mn3 = mn2;
                mn2 = x;
            } else if (x < mn3) {
                mn3 = x;
            }

            if (x > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = x;
            } else if (x > mx2) {
                mx3 = mx2;
                mx2 = x;
            } else if (x > mx3) {
                mx3 = x;
            }
        }

        return min({mx1 - mn3, mx2 - mn2, mx3 - mn1});
    }
};