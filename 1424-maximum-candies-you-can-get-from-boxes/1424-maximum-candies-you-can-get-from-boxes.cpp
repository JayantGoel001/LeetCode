class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> can_open(n), has_box(n), used(n);
        for (int i = 0; i < n; ++i) {
            can_open[i] = (status[i] == 1);
        }

        queue<int> q;
        int ans = 0;
        for (int box : initialBoxes) {
            has_box[box] = true;
            if (can_open[box]) {
                q.push(box);
                used[box] = true;
                ans += candies[box];
            }
        }

        while (!q.empty()) {
            int big_box = q.front();
            q.pop();
            for (int key : keys[big_box]) {
                can_open[key] = true;
                if (!used[key] && has_box[key]) {
                    q.push(key);
                    used[key] = true;
                    ans += candies[key];
                }
            }
            for (int box : containedBoxes[big_box]) {
                has_box[box] = true;
                if (!used[box] && can_open[box]) {
                    q.push(box);
                    used[box] = true;
                    ans += candies[box];
                }
            }
        }

        return ans;
    }
};