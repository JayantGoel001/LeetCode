class Solution {
    int segmentCost(const string& s, int l, int m,
                    const vector<vector<int>>& factors) {
        int best = m;
        for (int d : factors[m]) {
            int groups = m / d; // Each group contains groups characters
            int changes = 0;
            for (int offset = 0; offset < d; offset++) {
                for (int t = 0; t < groups / 2;
                     t++) { // Pair characters from opposite ends of the group
                    if (s[l + offset + t * d] !=
                        s[l + offset + (groups - 1 - t) * d]) {
                        changes++;
                    }
                }
            }
            best = min(best, changes);
        }
        return best;
    }

public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> factors(n + 1);
        // Precompute the proper divisors of each number
        for (int d = 1; d <= n / 2; d++) {
            for (int m = d * 2; m <= n; m += d) {
                factors[m].push_back(d);
            }
        }
        vector cost(n, vector<int>(n, 0));
        for (int l = 0; l + 1 < n; l++) {
            for (int r = l + 1; r < n;
                 r++) { // Each substring must have length at least 2
                cost[l][r] = segmentCost(s, l, r - l + 1, factors);
            }
        }
        vector<int> prev(n);
        for (int start = 0; start < n; start++) { // The case seg = 1
            prev[start] = cost[start][n - 1];
        }
        for (int seg = 2; seg <= k;
             seg++) { // Increase the number of segments from 2 to k
            vector<int> cur(n, n);
            int limit = n - 1 - 2 * (seg - 1);
            for (int start = 0; start + 2 * seg <= n;
                 start++) { // Leave at least 2*seg characters
                for (int e = start + 1; e <= limit; e++) {
                    cur[start] = min(cur[start], cost[start][e] + prev[e + 1]);
                }
            }
            prev.swap(cur);
        }
        return prev[0];
    }
};