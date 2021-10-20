class Solution {
public:
    
    static bool cmp(vector<int> &p1,vector<int> &p2){
        return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,decltype(&cmp)> pq(cmp);
        
        for(auto it : points){
            pq.push(it);
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>> v;
        while(!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        }
        return v;
    }
};