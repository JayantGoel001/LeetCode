class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n3 = nums.size(), n = n3 / 3;
        vector<long long> part1(n + 1);
        long long sum = 0;
        // max heap
        priority_queue<int> ql;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            ql.push(nums[i]);
        }
        part1[0] = sum;
        for (int i = n; i < n * 2; ++i) {
            sum += nums[i];
            ql.push(nums[i]);
            sum -= ql.top();
            ql.pop();
            part1[i - (n - 1)] = sum;
        }

        long long part2 = 0;
        // min heap
        priority_queue<int, vector<int>, greater<int>> qr;
        for (int i = n * 3 - 1; i >= n * 2; --i) {
            part2 += nums[i];
            qr.push(nums[i]);
        }
        long long ans = part1[n] - part2;
        for (int i = n * 2 - 1; i >= n; --i) {
            part2 += nums[i];
            qr.push(nums[i]);
            part2 -= qr.top();
            qr.pop();
            ans = min(ans, part1[i - n] - part2);
        }
        return ans;
    }
};