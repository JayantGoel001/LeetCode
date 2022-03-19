#define pip pair<int,pair<int,int>>
class Solution {
public:
    double ed2(int x,int y){
        return x * x + y * y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pip> pq;
        for(auto it : points){
            int dis = ed2(it[0],it[1]);
            pq.push({dis, {it[0], it[1]}});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>> v;
        while(!pq.empty()){
            v.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return v;
    }
};