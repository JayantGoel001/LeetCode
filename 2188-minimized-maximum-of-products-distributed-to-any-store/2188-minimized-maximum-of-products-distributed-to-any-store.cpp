class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();

        // Define a custom comparator for the priority queue
        // It sorts the pairs based on the ratio of their first to their second
        // element
        auto compareTypeStorePairs = [](pair<int, int>& a, pair<int, int>& b) {
            return (long long)a.first * b.second <
                   (long long)a.second * b.first;
        };

        // Helper array - useful for the efficient initialization of the
        // priority queue
        vector<pair<int, int>> typeStorePairsArray;

        // Push all product types to the array, after assigning one store to
        // each of them
        for (int i = 0; i < m; i++) {
            typeStorePairsArray.push_back({quantities[i], 1});
        }

        // Initialize the priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(compareTypeStorePairs)>
            typeStorePairs(typeStorePairsArray.begin(),
                           typeStorePairsArray.begin() + m);

        // Iterate over the remaining n - m stores.
        for (int i = 0; i < n - m; i++) {
            // Pop first element
            pair<int, int> pairWithMaxRatio = typeStorePairs.top();
            int totalQuantityOfType = pairWithMaxRatio.first;
            int storesAssignedToType = pairWithMaxRatio.second;
            typeStorePairs.pop();

            // Push same element after assigning one more store to its product
            // type
            typeStorePairs.push(
                {totalQuantityOfType, storesAssignedToType + 1});
        }

        // Pop first element
        pair<int, int> pairWithMaxRatio = typeStorePairs.top();
        int totalQuantityOfType = pairWithMaxRatio.first;
        int storesAssignedToType = pairWithMaxRatio.second;

        // Return the maximum minimum ratio
        return ceil((double)totalQuantityOfType / storesAssignedToType);
    }
};