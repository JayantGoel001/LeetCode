class Solution {
public:
    long long minimumTotalDistance(vector<int>& robots,
                                   vector<vector<int>>& factories) {
        // Sort robots and factories by position
        sort(begin(robots), end(robots));
        sort(begin(factories), end(factories));

        // Flatten factory positions according to their capacities
        vector<int> factoryPositions;
        for (auto& factory : factories) {
            for (int i = 0; i < factory[1]; i++) {
                factoryPositions.push_back(factory[0]);
            }
        }

        int robotCount = robots.size(), factoryCount = factoryPositions.size();
        vector<long long> next(factoryCount + 1, 0),
            current(factoryCount + 1, 0);

        current[factoryCount] = 1e12;

        // Fill DP table using two rows for optimization
        for (int i = robotCount - 1; i >= 0; i--) {
            for (int j = factoryCount - 1; j >= 0; j--) {
                // Assign current robot to current factory
                long long assign =
                    abs(robots[i] - factoryPositions[j]) + next[j + 1];
                // Skip current factory for this robot
                long long skip = current[j + 1];
                // Take the minimum option
                current[j] = min(assign, skip);
            }
            // Move to next robot
            next = current;
        }
        // Return minimum distance starting from the first robot
        return current[0];
    }
};