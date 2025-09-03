struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

struct PairEqual {
    bool operator()(const pair<int, int>& lhs,
                    const pair<int, int>& rhs) const {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
};

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        unordered_map<int, int> col;
        unordered_map<int, int> row;
        unordered_map<pair<int, int>, pair<int, int>, PairHash, PairEqual>
            coordinatesMap;

        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            col[x] = 0;
            row[y] = 0;
        }

        vector<int> colKeys;
        for (const auto& pair : col) {
            colKeys.push_back(pair.first);
        }
        sort(colKeys.begin(), colKeys.end());
        for (int i = 0; i < colKeys.size(); i++) {
            col[colKeys[i]] = i + 1;
        }

        vector<int> rowKeys;
        for (const auto& pair : row) {
            rowKeys.push_back(pair.first);
        }
        sort(rowKeys.begin(), rowKeys.end());
        for (int i = 0; i < rowKeys.size(); i++) {
            row[rowKeys[i]] = i + 1;
        }

        int nc = col.size() + 1;
        int nr = row.size() + 1;
        vector<vector<int>> m(nc, vector<int>(nr, 0));
        vector<vector<int>> prefixSum(nc, vector<int>(nr, 0));

        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            int c = col[x];
            int r = row[y];
            pair<int, int> key = make_pair(x, y);
            coordinatesMap[key] = make_pair(c, r);
            m[c][r] = 1;
        }

        for (int i = 1; i < nc; i++) {
            for (int j = 1; j < nr; j++) {
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] -
                                  prefixSum[i - 1][j - 1] + m[i][j];
            }
        }

        int ans = 0;
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) {
                     return a[1] > b[1];
                 }
                 return a[0] < b[0];
             });

        int n = points.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (points[i][1] >= points[j][1]) {
                    pair<int, int> key1 = make_pair(points[i][0], points[i][1]);
                    pair<int, int> key2 = make_pair(points[j][0], points[j][1]);
                    pair<int, int> coord1 = coordinatesMap[key1];
                    pair<int, int> coord2 = coordinatesMap[key2];
                    int c1 = coord1.first, r1 = coord1.second;
                    int c2 = coord2.first, r2 = coord2.second;
                    int cnt = prefixSum[c2][r1] - prefixSum[c1 - 1][r1] -
                              prefixSum[c2][r2 - 1] + prefixSum[c1 - 1][r2 - 1];
                    if (cnt == 2) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};