class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxWorkerTimes =
            *max_element(workerTimes.begin(), workerTimes.end());
        long long l = 1, r = static_cast<long long>(maxWorkerTimes) *
                             mountainHeight * (mountainHeight + 1) / 2;
        long long ans = 0;

        while (l <= r) {
            long long mid = (l + r) / 2;
            long long cnt = 0;
            for (int t : workerTimes) {
                long long work = mid / t;
                // find the largest k such that 1+2+...+k <= work
                long long k = (-1.0 + sqrt(1 + work * 8)) / 2 + eps;
                cnt += k;
            }
            if (cnt >= mountainHeight) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

private:
    static constexpr double eps = 1e-7;
};