class NumberContainers {
public:
    NumberContainers() {}

    void change(int index, int number) {
        // Update index to number mapping
        indexToNumbers[index] = number;

        // Add index to the min heap for this number
        numberToIndices[number].push(index);
    }

    int find(int number) {
        // If number doesn't exist in our map
        if (numberToIndices.find(number) == numberToIndices.end()) {
            return -1;
        }

        // Get reference to min heap for this number
        auto& minHeap = numberToIndices[number];

        // Keep checking top element until we find valid index
        while (!minHeap.empty()) {
            int index = minHeap.top();

            // If index still maps to our target number, return it
            if (indexToNumbers[index] == number) {
                return index;
            }

            // Otherwise remove this stale index
            minHeap.pop();
        }

        return -1;
    }

private:
    // Map to store number -> min heap of indices
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>>
        numberToIndices;
    // Map to store index -> number
    unordered_map<int, int> indexToNumbers;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */