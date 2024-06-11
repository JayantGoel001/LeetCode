class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<arr2.size();i++) {
            mp[arr2[i]] = i + 1;
        }
        
        sort(arr1.begin(),arr1.end(), [&](const int a, const int b)->bool{
            int x = mp[a] == 0 ? arr2.size() + a + 1 : mp[a];
            int y = mp[b] == 0 ? arr2.size() + b + 1 : mp[b];
            
            return x <= y;
        });
        
        return arr1;
    }
};