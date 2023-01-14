class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it : arr){
            mp[it]++;
        }
        unordered_map<int,int> x;
        for(auto it : mp){
            x[it.second]++;
        }
        for(auto it : x){
            if(it.second > 1){
                return false;
            }
        }
        return true;
    }
};