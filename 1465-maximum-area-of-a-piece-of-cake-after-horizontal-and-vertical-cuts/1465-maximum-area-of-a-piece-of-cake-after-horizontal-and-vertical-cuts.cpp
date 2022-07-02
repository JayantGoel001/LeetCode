#define ll long long int
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCut, vector<int>& vCut) {
        sort(hCut.begin(),hCut.end());
        sort(vCut.begin(),vCut.end());
        
        hCut.push_back(h);
        vCut.push_back(w);

        ll MOD = 1e9 + 7;
        ll maxi = 0;
        
        int maxh = 0;
        int maxv = 0;
        for(int i=0;i<hCut.size();i++){
            maxh = max(maxh,hCut[i] - (i == 0 ? 0 : hCut[i - 1]));
        }
        
        for(int i=0;i<vCut.size();i++){
            maxv = max(maxv,vCut[i] - (i == 0 ? 0 : vCut[i - 1]));
        }
        return ((maxh % MOD) * (maxv % MOD))%MOD;
    }
};