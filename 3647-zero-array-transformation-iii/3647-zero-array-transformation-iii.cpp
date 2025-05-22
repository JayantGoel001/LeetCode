class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        priority_queue<int> heap;
        vector<int> deltaArray(nums.size() + 1, 0);
        int operations = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            operations += deltaArray[i];
            while (j < queries.size() && queries[j][0] == i) {
                heap.push(queries[j][1]);
                ++j;
            }
            while (operations < nums[i] && !heap.empty() && heap.top() >= i) {
                operations += 1;
                deltaArray[heap.top() + 1] -= 1;
                heap.pop();
            }
            if (operations < nums[i]) {
                return -1;
            }
        }
        return heap.size();
    }
};