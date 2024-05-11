class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double totalCost = numeric_limits<double>::max();
        double currentTotalQuality = 0;
        // Store wage-to-quality ratio along with quality
        vector<pair<double, int>> wageToQualityRatio;

        // Calculate wage-to-quality ratio for each worker
        for (int i = 0; i < n; i++) {
            wageToQualityRatio.push_back(
                {static_cast<double>(wage[i]) / quality[i], quality[i]});
        }

        // Sort workers based on their wage-to-quality ratio
        sort(wageToQualityRatio.begin(), wageToQualityRatio.end());

        // Use a priority queue to keep track of the highest quality workers
        priority_queue<int> highestQualityWorkers;

        // Iterate through workers
        for (int i = 0; i < n; i++) {
            highestQualityWorkers.push(wageToQualityRatio[i].second);
            currentTotalQuality += wageToQualityRatio[i].second;

            // If we have more than k workers,
            // remove the one with the highest quality
            if (highestQualityWorkers.size() > k) {
                currentTotalQuality -= highestQualityWorkers.top();
                highestQualityWorkers.pop();
            }

            // If we have exactly k workers,
            // calculate the total cost and update if it's the minimum
            if (highestQualityWorkers.size() == k) {
                totalCost = min(totalCost, currentTotalQuality *
                                               wageToQualityRatio[i].first);
            }
        }
        return totalCost;
    }
};