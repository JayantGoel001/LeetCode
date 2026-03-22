class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int end = 0;
        int start = costs.size()-1;

        auto cmp = [&](const int x, const int y)->bool{
            if (costs[x] == costs[y]) return x > y;
            return costs[x] > costs[y];
        };

        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int i = 0;
        while(i++ < candidates) {
            pq.push(end++);
        }
        i = 0;
        while(i++ < candidates && end <= start) {
            pq.push(start--);
        }
        
        long long ans = 0ll;
        while(k--) {
            int top = pq.top();
            pq.pop();

            ans += costs[top];

            if (end > start) continue;

            if (top < end) {
                pq.push(end++);
            } else {
                pq.push(start--);
            }
        }

        return ans;
    }
};