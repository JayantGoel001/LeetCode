#define pii pair<int,int>
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int end = 0;
        int start = costs.size()-1;

        auto cmp = [&](const pii x, const pii y)->bool{
            if (costs[x.first] == costs[y.first]) return x.first > y.first;
            return costs[x.first] > costs[y.first];
        };

        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
        int i = 0;
        while(i++ < candidates) {
            pq.push({end++, 1});
        }
        i = 0;
        while(i++ < candidates && end <= start) {
            pq.push({start--, -1});
        }
        
        long long ans = 0ll;
        while(k--) {
            pii top = pq.top();
            pq.pop();

            ans += costs[top.first];

            if (end > start) continue;

            if (top.second == 1) {
                pq.push({end++, 1});
            } else {
                pq.push({start--, -1});
            }
        }

        return ans;
    }
};