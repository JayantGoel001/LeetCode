class Solution {
public:
    long repairCars(vector<int>& ranks, int cars) {
        // Count the frequency of each rank
        unordered_map<int, int> count;
        for (int rank : ranks) {
            count[rank] += 1;
        }

        // Create a Min-heap (priority_queue in C++ std library) storing [time,
        // rank, n, count]
        // - time: time for the next repair
        // - rank: mechanic's rank
        // - n: cars repaired by this mechanic
        // - count: number of mechanics with this rank
        // Initial time = rank (as rank * 1^2 = rank)
        auto comp = [](vector<long>& a, vector<long>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<long>, vector<vector<long>>, decltype(comp)>
            minHeap(comp);

        // Add initial entries to the heap
        for (auto it : count) {
            int rank = it.first;
            // Elements: [time, rank, cars_repaired, mechanic_count]
            minHeap.push({rank, rank, 1, it.second});
        }

        long time = 0;
        // Process until all cars are repaired
        while (cars > 0) {
            // Pop the mechanic with the smallest current repair time
            vector<long> current = minHeap.top();
            minHeap.pop();
            time = current[0];
            int rank = current[1];
            long n = current[2];
            int mechCount = current[3];

            // Deduct the number of cars repaired by this mechanic group
            cars -= mechCount;

            // Increment the number of cars repaired by this mechanic
            n += 1;

            // Push the updated repair time back into the heap
            // The new repair time is rank * n^2 (time increases quadratically
            // with n)
            minHeap.push({rank * n * n, rank, n, mechCount});
        }

        return time;
    }
};