class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int maxi = 0;
        for(auto it : gain){
            sum += it;
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};