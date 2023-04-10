class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int start = 0;
        int count = 0;
        
        for(int i=0;i<s.size() && start < g.size();i++){
            if(s[i] >= g[start]){
                count++;
                start++;
            }
        }
        return count;
    }
};