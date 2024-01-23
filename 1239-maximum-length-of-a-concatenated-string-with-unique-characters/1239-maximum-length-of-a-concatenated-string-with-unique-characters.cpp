class Solution {
public:
    int maxLength(vector<string>& arr) {
        int result = 0;
        dfs(arr, "", 0, result);
        return result;
    }

private:
    void dfs(const vector<string>& arr, const string& path, int idx, int& result) {
        if (isUniqueChars(path)) {
            result = max(result, static_cast<int>(path.length()));
        }

        if (idx == arr.size() || !isUniqueChars(path)) {
            return;
        }

        for (int i = idx; i < arr.size(); i++) {
            dfs(arr, path + arr[i], i + 1, result);
        }
    }

    bool isUniqueChars(const string& s) {
        unordered_set<char> set;
        for (char c : s) {
            if (set.count(c)) {
                return false;
            }
            set.insert(c);
        }
        return true;
    }
};