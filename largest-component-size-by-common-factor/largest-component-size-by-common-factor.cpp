class Solution {
    void init(vector<int> &par)
    {
        for(int i=0;i<=100001;i++)
            par.push_back(i);
    }
    
    int findPar(int u,vector<int> &par)
    {
        if(par[u] == u) return u;
        
        return par[u] = findPar(par[u],par);
    }
    
    void unn(int u,int v,vector<int> &par)
    {
        int x = findPar(u,par) , y = findPar(v,par);
        if(x != y) par[x] = y;
    }
public:
    int largestComponentSize(vector<int>& nums) {
        vector<int> par;
        init(par);
        
        for(auto &val : nums)
        {
            for(int k=2;k<=sqrt(val);k++)
            {
                if(val%k == 0)
                {
                    unn(val,k,par);
                    unn(val,val/k,par);
                }
            }
        }
        
        int cnt = 0;
        unordered_map<int,int> mp;
        
        for(auto &val : nums)
        {
            int x = findPar(val,par);
            mp[x]++;
            cnt = max(cnt,mp[x]);
        }
        
        return cnt;
    }
};