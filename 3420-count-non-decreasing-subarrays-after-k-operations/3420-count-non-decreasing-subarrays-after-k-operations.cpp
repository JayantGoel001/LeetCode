class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long operations = 0;
        // Maintain the window maximum with a priority queue
        priority_queue<pair<int, int>> q;
        // Record the set of elements covered by this index
        vector<vector<int>> cnt(n);
        // Index of the first greater-or-equal element to the right
        vector<int> pos(n, n);
        // Decreasing monotonic stack
        stack<int> st;

        for (int left = 0, right = 0; right < n; right++) {
            // Maintain the monotonic stack
            while (!st.empty() && nums[right] >= nums[st.top()]) {
                pos[st.top()] = right;
                st.pop();
            }
            // The stack top is the nearest greater element to the left of
            // nums[right]
            if (!st.empty()) {
                cnt[st.top()].push_back(right);
            }
            st.push(right);

            // The priority queue front is the window maximum
            q.emplace(nums[right], right);
            // Adding nums[right] increases the operation count
            operations += max(0, q.top().first - nums[right]);

            // The minimum operation count exceeds k; shrink the window
            while (operations > k) {
                // Removing nums[left] from the window decreases the operation
                // count
                for (int i : cnt[left]) {
                    // Subtract the contribution
                    operations -=
                        (long long)(nums[left] - nums[i]) *
                        (min(pos[i], right + 1) - i);
                }
                left++;
            }

            // Remove elements with indices less than left from the priority
            // queue
            while (!q.empty() && q.top().second < left) {
                q.pop();
            }

            // There are right - left + 1 valid contiguous subarrays ending at
            // right
            ans += right - left + 1;
        }

        return ans;
    }
};