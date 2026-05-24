class Solution {
private:
    vector<int> f;

public:
    void dfs(vector<int>& arr, int id, int d, int n) {
        if (f[id] != -1) {
            return;
        }
        f[id] = 1;
        for (int i = id - 1; i >= 0 && id - i <= d && arr[id] > arr[i]; --i) {
            dfs(arr, i, d, n);
            f[id] = max(f[id], f[i] + 1);
        }
        for (int i = id + 1; i < n && i - id <= d && arr[id] > arr[i]; ++i) {
            dfs(arr, i, d, n);
            f[id] = max(f[id], f[i] + 1);
        }
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        f.resize(n, -1);
        for (int i = 0; i < n; ++i) {
            dfs(arr, i, d, n);
        }
        return *max_element(f.begin(), f.end());
    }
};