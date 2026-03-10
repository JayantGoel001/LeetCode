class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int sum = 0;
        for(int i=1;i<=gain.size();i++) {
            sum += gain[i - 1];
            maxi = max(maxi, sum);
        }

        return maxi;
    }
};