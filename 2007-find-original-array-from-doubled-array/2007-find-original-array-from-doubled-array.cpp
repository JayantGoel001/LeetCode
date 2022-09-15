class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n%2!=0) return {};
        
        unordered_map<int,int> mp;
        vector<int> res;
        sort(changed.begin(),changed.end());
        
        for(auto &x : changed){
            if(x%2==0 and mp.count(x/2)){
                res.push_back(x/2);
                mp[x/2]--;
                if(mp[x/2]==0) mp.erase(x/2);
            }
            else{
                mp[x]++;
            }
        }
        
        int m = res.size();
        if(2*m == n) return res;
        return {};
    }
};