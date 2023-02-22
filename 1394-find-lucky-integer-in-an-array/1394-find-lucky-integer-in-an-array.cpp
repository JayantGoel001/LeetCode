class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it : arr){
            mp[it]++;
        }
        int maxi = -1;
        for(auto it : mp){
            if(it.first == it.second){
                maxi = max(maxi, it.first);
            }
        }
        return maxi;
    }
};