class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = nums1[0];
        bool hasOdd = false;
        for (int v : nums1) {
            if (v < mn) {
                mn = v;
            }
            if (v & 1) {
                hasOdd = true;
            }
        }
        if (mn & 1) {
            return true;
        }
        return !hasOdd;
    }
};