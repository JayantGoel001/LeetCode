class Solution {
public:
    int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<long> > eng;
        priority_queue<long, vector<long>, greater<long> > pq;
        for(int i = 0; i < n; i++) {
            eng.push_back({efficiency[i], speed[i]});
        }
        sort(eng.begin(), eng.end());
        long res = 0, sum = 0;
        for(int i = eng.size()-1; i >= 0; i--) {
            sum += eng[i][1];
            pq.push(eng[i][1]);
            while(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            res = max(res, sum*eng[i][0]);
        }
        return res%mod;
    }
};