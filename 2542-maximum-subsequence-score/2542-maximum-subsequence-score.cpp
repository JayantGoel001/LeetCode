#define pii pair<int,int>
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int size = nums1.size();
        vector<pii> v;
        for(int i=0;i<size;i++) {
            v.push_back({nums1[i], nums2[i]});
        }

        sort(v.begin(), v.end(), [&](const pii a, const pii b)->bool{
            return a.second > b.second;
        });

        long long sum = 0;
        long long res = 0;

        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it : v) {
            sum += it.first;
            int mini = it.second;
            pq.push(it.first);

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                res = max(res, sum * mini);
            }
        }

        return res;
    }
};