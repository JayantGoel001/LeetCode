class Solution {
public:
    int candy(vector<int>& ratings) {
        int candies = ratings.size();

        int i = 1;
        while(i < ratings.size()) {
            while(i < ratings.size() && ratings[i - 1] == ratings[i]) i++;

            int peak = 0;
            while(i < ratings.size() && ratings[i - 1] < ratings[i]) {
                candies += ++peak;
                i++;
            }
            int valley = 0;
            while(i < ratings.size() && ratings[i - 1] > ratings[i]) {
                candies += ++valley;
                i++;
            }
            candies -= min(peak, valley);
        }

        return candies;
    }
};