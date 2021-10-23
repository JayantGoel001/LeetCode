class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto it : arr1){
            mp[it]++;
        }
        vector<int> v;
        for(auto it : arr2){
            int x = mp[it];
            while(x--){
                v.push_back(it);
            }
            mp[it] = 0;
        }
        for(auto it : mp){
            int x = mp[it.first];
            while(x){
                v.push_back(it.first);
                x--;
            }
        }
        return v;
    }
};