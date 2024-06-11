class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto it : arr1) {
            mp[it]++;
        }
        
        vector<int> v;
        for(auto it : arr2) {
            while(mp[it]) {
                v.push_back(it);
                mp[it]--;
            }
        }
        
        for(auto it : mp) {
            while(mp[it.first]) {
                v.push_back(it.first);
                mp[it.first]--;
            }
        }
        
        return v;
    }
};