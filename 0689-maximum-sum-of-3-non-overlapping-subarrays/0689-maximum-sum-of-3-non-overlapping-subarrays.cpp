class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // Variables to track the best indices for one, two, and three subarray
        // configurations
        int bestSingleStart = 0;
        vector<int> bestDoubleStart = {0, k};
        vector<int> bestTripleStart = {0, k, k * 2};

        // Compute the initial sums for the first three subarrays
        int currentWindowSumSingle = 0;
        for (int i = 0; i < k; i++) {
            currentWindowSumSingle += nums[i];
        }

        int currentWindowSumDouble = 0;
        for (int i = k; i < k * 2; i++) {
            currentWindowSumDouble += nums[i];
        }

        int currentWindowSumTriple = 0;
        for (int i = k * 2; i < k * 3; i++) {
            currentWindowSumTriple += nums[i];
        }

        // Track the best sums found so far
        int bestSingleSum = currentWindowSumSingle;
        int bestDoubleSum = currentWindowSumSingle + currentWindowSumDouble;
        int bestTripleSum = currentWindowSumSingle + currentWindowSumDouble +
                            currentWindowSumTriple;

        // Sliding window pointers for the subarrays
        int singleStartIndex = 1;
        int doubleStartIndex = k + 1;
        int tripleStartIndex = k * 2 + 1;

        // Slide the windows across the array
        while (tripleStartIndex <= nums.size() - k) {
            // Update the sums using the sliding window technique
            currentWindowSumSingle = currentWindowSumSingle -
                                     nums[singleStartIndex - 1] +
                                     nums[singleStartIndex + k - 1];
            currentWindowSumDouble = currentWindowSumDouble -
                                     nums[doubleStartIndex - 1] +
                                     nums[doubleStartIndex + k - 1];
            currentWindowSumTriple = currentWindowSumTriple -
                                     nums[tripleStartIndex - 1] +
                                     nums[tripleStartIndex + k - 1];

            // Update the best single subarray start index if a better sum is
            // found
            if (currentWindowSumSingle > bestSingleSum) {
                bestSingleStart = singleStartIndex;
                bestSingleSum = currentWindowSumSingle;
            }

            // Update the best double subarray start indices if a better sum is
            // found
            if (currentWindowSumDouble + bestSingleSum > bestDoubleSum) {
                bestDoubleStart[0] = bestSingleStart;
                bestDoubleStart[1] = doubleStartIndex;
                bestDoubleSum = currentWindowSumDouble + bestSingleSum;
            }

            // Update the best triple subarray start indices if a better sum is
            // found
            if (currentWindowSumTriple + bestDoubleSum > bestTripleSum) {
                bestTripleStart[0] = bestDoubleStart[0];
                bestTripleStart[1] = bestDoubleStart[1];
                bestTripleStart[2] = tripleStartIndex;
                bestTripleSum = currentWindowSumTriple + bestDoubleSum;
            }

            // Move the sliding windows forward
            singleStartIndex += 1;
            doubleStartIndex += 1;
            tripleStartIndex += 1;
        }

        // Return the starting indices of the three subarrays with the maximum
        // sum
        return bestTripleStart;
    }
};