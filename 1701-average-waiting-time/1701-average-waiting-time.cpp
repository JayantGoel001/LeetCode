class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int nextIdleTime = 0;
        long long netWaitTime = 0;

        for (int i = 0; i < customers.size(); i++) {
            // The next idle time for the chef is given by the time of delivery
            // of current customer's order.
            nextIdleTime = max(customers[i][0], nextIdleTime) + customers[i][1];

            // The wait time for the current customer is the difference between
            // his delivery time and arrival time.
            netWaitTime += nextIdleTime - customers[i][0];
        }

        // Divide by total customers to get average.
        double averageWaitTime =
            static_cast<double>(netWaitTime) / customers.size();
        return averageWaitTime;
    }
};