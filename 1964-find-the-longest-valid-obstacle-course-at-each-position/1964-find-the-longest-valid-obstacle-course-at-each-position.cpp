class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> v, ans(obstacles.size(), 1);
        
        for(int i=0;i<obstacles.size();i++){
            int pos = upper_bound(v.begin(), v.end(), obstacles[i]) - v.begin();
            
            if(pos == v.size()){
                v.push_back(obstacles[i]);
            }else{
                v[pos] = obstacles[i];
            }
            ans[i] = pos + 1;
        }
        return ans;
    }
};