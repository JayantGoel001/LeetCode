class Solution {
public:
    int minimumPushes(string word) {
        // Frequency map to store count of each letter
        unordered_map<char, int> frequencyMap;

        // Count occurrences of each letter
        for (char& c : word) {
            ++frequencyMap[c];
        }

        // Priority queue to store frequencies in descending order
        priority_queue<int> frequencyQueue;

        // Push all frequencies into the priority queue
        for (const auto& entry : frequencyMap) {
            frequencyQueue.push(entry.second);
        }

        int totalPushes = 0;
        int index = 0;

        // Calculate total number of presses
        while (!frequencyQueue.empty()) {
            totalPushes += (1 + (index / 8)) * frequencyQueue.top();
            frequencyQueue.pop();
            index++;
        }

        return totalPushes;
    }
};