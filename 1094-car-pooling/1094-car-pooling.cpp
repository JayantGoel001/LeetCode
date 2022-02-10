class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1001,0);
        
        for(auto it : trips){
            v[it[1]] += it[0];
            v[it[2]] -= it[0];
        }
        int sum = 0;
        for(auto it : v){
            sum += it;
            if(sum > capacity){
                return false;
            }
        }
        return true;
    }
};