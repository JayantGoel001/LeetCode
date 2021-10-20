class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int prev = 0;
        for(auto it : gain){
            maxi = max(maxi,it + prev);
            prev += it;
        }
        return maxi;
    }
};