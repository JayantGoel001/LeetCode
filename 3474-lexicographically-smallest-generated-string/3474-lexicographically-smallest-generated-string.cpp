class Solution {
    vector<int> calc_z(const string& s) {
        int n = s.size();
        vector<int> z(n);
        int box_l = 0, box_r = 0; // Left and right boundaries of the z-box (inclusive)
        for (int i = 1; i < n; i++) {
            if (i <= box_r) {
                z[i] = min(z[i - box_l], box_r - i + 1);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                box_l = i;
                box_r = i + z[i];
                z[i]++;
            }
        }
        z[0] = n;
        return z;
    }

public:
    string generateString(string s, string t) {
        int n = s.size(), m = t.size();
        string ans(n + m - 1, '?');

        // Process T
        vector<int> z = calc_z(t);
        int pre = -m;
        for (int i = 0; i < n; i++) {
            if (s[i] != 'T') {
                continue;
            }
            int size = max(pre + m - i, 0);
            // The prefix and suffix of t with length size must be equal
            if (size > 0 && z[m - size] < size) {
                return "";
            }
            // Positions after size are all '?', so fill in t
            for (int j = size; j < m; j++) {
                ans[i + j] = t[j];
            }
            pre = i;
        }

        // Compute the nearest undecided position <= i
        vector<int> pre_q(ans.size());
        pre = -1;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == '?') {
                ans[i] = 'a'; // Initial value for undecided positions is a
                pre = i;
            }
            pre_q[i] = pre;
        }

        // Find positions in ans equal to t, using KMP or the Z-function
        z = calc_z(t + ans);

        // Process F
        for (int i = 0; i < n; i++) {
            if (s[i] != 'F') {
                continue;
            }
            // The substring must not equal t
            if (z[m + i] < m) {
                continue;
            }
            // Find the last undecided position
            int j = pre_q[i + m - 1];
            if (j < i) { // None exists
                return "";
            }
            ans[j] = 'b';
            i = j; // Jump directly to j
        }

        return ans;
    }
};