class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // Sort the original array
        sort(arr.begin(), arr.end());
        vector<vector<int>> answer;

        // Initialize minimum difference `minPairDiff` as a huge integer in order not 
        // to miss the absolute difference of the first pair. 
        int minPairDiff = INT_MAX;

        // Traverse the sorted array
        for (int i = 0; i < arr.size() - 1; ++i) {            
            // For the absolute value `currPairDiff` of the current pair:
            int currPairDiff = arr[i + 1] - arr[i];

            // If `currPairDiff` equals `minPairDiff`, add this pair to the answer list.
            // If `currPairDiff` is smaller than `minPairDiff`, discard all pairs in the answer list, 
            // add this pair to the answer list and update `minPairDiff`.
            // If `currPairDiff` is larger than `minPairDiff`, we just go ahead.
            if (currPairDiff == minPairDiff) {
                answer.push_back({arr[i], arr[i + 1]});           
            } else if (currPairDiff < minPairDiff) {
                answer = {};
                answer.push_back({arr[i], arr[i + 1]});
                minPairDiff = currPairDiff;
            }
        }

        return answer;
    }
};
