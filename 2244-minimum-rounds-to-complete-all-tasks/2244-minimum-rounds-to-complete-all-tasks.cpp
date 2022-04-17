class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto it : tasks){
            mp[it]++;
        }
        int count = 0;
        for(auto it : mp){
            if(it.second < 2){
                return -1;
            }
            int _3 = 0;
            int _2 = 0;
            int x = it.second;
            _3 = x/3;
            x -= 3 * _3;
            
            _2 = x/2;
            x -= 2 * _2;
            count += _3 + _2 + (x != 0);
        }
        return count;
    }
};