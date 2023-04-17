class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = 0;
        for(auto it : candies){
            maxi = max(maxi, it);
        }
        vector<bool> v;
        for(auto it : candies){
            v.push_back(it + extraCandies >= maxi);
        }
        return v;
    }
};