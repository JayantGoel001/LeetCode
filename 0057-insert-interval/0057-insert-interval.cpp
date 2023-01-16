class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> temp, v;
        
        bool flag = false;
        for(auto it : intervals){
            if(it[0] > newInterval[0] && !flag){
                temp.push_back(newInterval);
                flag = true;
            }
            temp.push_back(it);
        }
        if(!flag){
            temp.push_back(newInterval);
        }
        
        for(auto it : temp){
            if(v.empty() || v.back()[1] < it[0]){
                v.push_back(it);
            }else{
                v.back()[1] = max(v.back()[1], it[1]);
            }
        }
        return v;
    }
};