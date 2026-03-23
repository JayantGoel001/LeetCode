class Solution {
public:
    long long getHours(vector<int> &piles, int k) {
        long long count = 0;
        for(auto it : piles) {
            count += ceil((double)it/k);
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low)/2;

            if (getHours(piles, mid) <= (long long)h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};