class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> digitSum(n);
        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            digitSum[i] = sum;
        }

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            if (digitSum[a] != digitSum[b]) {
                return digitSum[a] < digitSum[b];
            }
            return nums[a] < nums[b];
        });

        vector<int> targetPos(n);
        for (int pos = 0; pos < n; pos++) {
            targetPos[indices[pos]] = pos;
        }

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        int components = n;

        function<int(int)> find = [&](int x) -> int {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        for (int i = 0; i < n; i++) {
            int ri = find(i);
            int rj = find(targetPos[i]);
            if (ri != rj) {
                parent[ri] = rj;
                components--;
            }
        }

        return n - components;
    }
};