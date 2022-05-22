#define ll long long int
class Solution {
public:
    
    int minimumLines(vector<vector<int>>& sp) {
        int n = sp.size();
        ll prevX = INT_MAX;
        ll prevY = INT_MAX;
        
        int count = 0;
        sort(sp.begin(),sp.end());
        
        for(int i=0;i<n-1;i++){
            ll my = (sp[i + 1][1] - sp[i][1]);
            ll mx = (sp[i + 1][0] - sp[i][0]);
            
            if((prevX == INT_MAX && prevY == INT_MAX) || prevX * my != mx * prevY){
                prevX = mx;
                prevY = my;
                count++;
            }
        }
        return count;
    }
};