#define pis pair<int,string>
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pis> pq;
        
        for(int i=0;i<names.size();i++){
            pq.push({heights[i], names[i]});
        }
        vector<string> v;
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};