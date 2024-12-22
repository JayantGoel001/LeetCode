class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        vector<vector<vector<int>>> storeQueries(heights.size());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            maxIndex;
        vector<int> result(queries.size(), -1);

        // Store the mappings for all queries in storeQueries.
        for (int currQuery = 0; currQuery < queries.size(); currQuery++) {
            int a = queries[currQuery][0], b = queries[currQuery][1];
            if (a < b && heights[a] < heights[b]) {
                result[currQuery] = b;
            } else if (a > b && heights[a] > heights[b]) {
                result[currQuery] = a;
            } else if (a == b) {
                result[currQuery] = a;
            } else {
                storeQueries[max(a, b)].push_back(
                    {max(heights[a], heights[b]), currQuery});
            }
        }

        for (int index = 0; index < heights.size(); index++) {
            // If the priority queue's minimum pair value is less than the
            // current index of height, it is an answer to the query.
            while (!maxIndex.empty() && maxIndex.top()[0] < heights[index]) {
                result[maxIndex.top()[1]] = index;
                maxIndex.pop();
            }
            // Push the with their maximum index as the current index in the
            // priority queue.
            for (auto& element : storeQueries[index]) {
                maxIndex.push(element);
            }
        }
        return result;
    }
};