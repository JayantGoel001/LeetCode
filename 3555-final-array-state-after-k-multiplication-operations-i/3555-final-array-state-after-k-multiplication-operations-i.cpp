class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<pair<int, int>> heap;
        for (int i = 0; i < nums.size(); i++) {
            heap.push_back({nums[i], i});
        }

        make_heap(heap.begin(), heap.end(), greater<>());

        while (k--) {
            pop_heap(heap.begin(), heap.end(), greater<>());
            auto [value, i] = heap.back();
            heap.pop_back();

            nums[i] *= multiplier;
            heap.push_back({nums[i], i});
            push_heap(heap.begin(), heap.end(), greater<>());
        }

        return nums;
    }
};