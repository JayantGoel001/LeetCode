class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Create an unordered_set for efficient lookup of values in nums
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());

        // Handle the case where the head node needs to be removed
        while (head != nullptr && valuesToRemove.count(head->val) > 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // If the list is empty after removing head nodes, return nullptr
        if (head == nullptr) {
            return nullptr;
        }

        // Iterate through the list, removing nodes with values in the set
        ListNode* current = head;
        while (current->next != nullptr) {
            if (valuesToRemove.contains(current->next->val)) {
                // Store the node to be deleted
                ListNode* temp = current->next;
                // Skip the next node by updating the pointer
                current->next = current->next->next;
                // Delete the removed node
                delete temp;
            } else {
                // Move to the next node
                current = current->next;
            }
        }

        return head;
    }
};