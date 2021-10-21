class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> v;
        int i = 0;
        int j = 0;
        
        int n = f.size();
        int m = s.size();
        
        while(i < n && j < m){
            int low = max(f[i][0],s[j][0]);
            int high = min(f[i][1],s[j][1]);
            
            if(low <= high){
                v.push_back({low,high});
            }
            
            if(f[i][1] < s[j][1]){
                i++;
            }else{
                j++;
            }
        }
        return v;
    }
};