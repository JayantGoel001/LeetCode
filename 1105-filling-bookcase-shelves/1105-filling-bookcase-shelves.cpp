class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // dp[i] will store the minimum height of the bookcase containing all
        // books up to and excluding i
        vector<int> dp(books.size() + 1, 0);

        // Base cases
        dp[0] = 0;
        dp[1] = books[0][1];

        for (int i = 1; i <= books.size(); ++i) {
            // new shelf built to hold current book
            int remainingShelfWidth = shelfWidth - books[i - 1][0];
            int maxHeight = books[i - 1][1];
            dp[i] = dp[i - 1] + maxHeight;

            int j = i - 1;
            // calculate the height when previous books are added onto a new
            // shelf
            while (j > 0 && remainingShelfWidth - books[j - 1][0] >= 0) {
                remainingShelfWidth -= books[j - 1][0];
                maxHeight = max(maxHeight, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + maxHeight);
                j--;
            }
        }

        return dp[books.size()];
    }
};