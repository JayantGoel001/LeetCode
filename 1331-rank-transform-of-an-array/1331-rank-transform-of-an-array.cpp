class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Store the rank for each number in arr.
        map<int, vector<int>> numToIndices;

        for (int i = 0; i < arr.size(); i++) {
            numToIndices[arr[i]].push_back(i);
        }

        int rank = 1;
        for (auto& pair : numToIndices) {
            for (int index : pair.second) {
                arr[index] = rank;
            }
            rank++;
        }
        return arr;
    }
};