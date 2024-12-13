class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        vector<bool> marked(nums.size());

        auto cmp = [](pair<int, int>& pair1, pair<int, int>& pair2) {
            if (pair1.first != pair2.first) return pair1.first > pair2.first;
            return pair1.second > pair2.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
            heap(cmp);

        for (int i = 0; i < nums.size(); ++i) {
            heap.push(make_pair(nums[i], i));
        }

        while (!heap.empty()) {
            pair<int, int> element = heap.top();
            heap.pop();
            int number = element.first;
            int index = element.second;

            if (!marked[index]) {
                ans += number;
                marked[index] = true;

                // mark adjacent elements if they exist
                if (index - 1 >= 0) {
                    marked[index - 1] = true;
                }
                if (index + 1 < nums.size()) {
                    marked[index + 1] = true;
                }
            }
        }

        return ans;
    }
};