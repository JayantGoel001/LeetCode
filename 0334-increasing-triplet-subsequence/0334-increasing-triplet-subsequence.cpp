class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX;
        int b = INT_MAX;

        for(auto it : nums) {
            if (a >= it) {
                a = it;
            } else if (b >= it) {
                b = it;
            } else {
                return true;
            }
        }

        return false;
    }
};