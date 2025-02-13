class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> min_heap(nums.begin(),
                                                                   nums.end());
        int num_operations = 0;

        while (min_heap.top() < k) {
            long x = min_heap.top();
            min_heap.pop();
            long y = min_heap.top();
            min_heap.pop();
            min_heap.push(min(x, y) * 2 + max(x, y));

            num_operations++;
        }
        return num_operations;
    }
};