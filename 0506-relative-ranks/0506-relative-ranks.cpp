class Solution {
private:
    int findMax(vector<int>& score) {
        int maxScore = 0;
        for (int s : score) {
            if (s > maxScore) {
                maxScore = s;
            }
        }
        return maxScore;
    }
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int N = score.size();

        // Add the original index of each score to the array
        // Where the score is the key
        int M = findMax(score);
        vector<int> scoreToIndex(M + 1, 0);
        for (int i = 0; i < N; i++) {
            scoreToIndex[score[i]] = i + 1;
        }

        const vector<string> MEDALS = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        // Assign ranks to athletes
        vector<string> rank(N);
        int place = 1;
        for (int i = M; i >= 0; i--) {
            if (scoreToIndex[i] != 0) {
                int originalIndex = scoreToIndex[i] - 1;
                if (place < 4) {
                    rank[originalIndex] = MEDALS[place - 1];
                } else {
                    rank[originalIndex] = to_string(place);
                }
                place++;
            }
        }
        return rank;
    }
};