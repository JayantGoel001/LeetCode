class Solution {
public:
    bool getHours(vector<int> &piles, int k, int h) {
        int count = 0;
        for(auto it : piles) {
            count += it/k + !!(it % k);
            if (count > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low)/2;

            if (getHours(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};