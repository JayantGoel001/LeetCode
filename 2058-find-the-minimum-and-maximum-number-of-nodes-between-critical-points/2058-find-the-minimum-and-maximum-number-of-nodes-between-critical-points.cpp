class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result = {-1, -1};

        // Initialize minimum distance to the maximum possible value
        int minDistance = INT_MAX;

        // Pointers to track the previous node, current node, and indices
        ListNode* previousNode = head;
        ListNode* currentNode = head->next;
        int currentIndex = 1;
        int previousCriticalIndex = 0;
        int firstCriticalIndex = 0;

        while (currentNode->next != nullptr) {
            // Check if the current node is a local maxima or minima
            if ((currentNode->val < previousNode->val &&
                 currentNode->val < currentNode->next->val) ||
                (currentNode->val > previousNode->val &&
                 currentNode->val > currentNode->next->val)) {
                // If this is the first critical point found
                if (previousCriticalIndex == 0) {
                    previousCriticalIndex = currentIndex;
                    firstCriticalIndex = currentIndex;
                } else {
                    // Calculate the minimum distance between critical points
                    minDistance =
                        min(minDistance, currentIndex - previousCriticalIndex);
                    previousCriticalIndex = currentIndex;
                }
            }

            // Move to the next node and update indices
            currentIndex++;
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        // If at least two critical points were found
        if (minDistance != INT_MAX) {
            int maxDistance = previousCriticalIndex - firstCriticalIndex;
            result = {minDistance, maxDistance};
        }

        return result;
    }
};