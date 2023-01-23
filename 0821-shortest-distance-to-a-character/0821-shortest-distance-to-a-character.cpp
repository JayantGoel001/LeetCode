class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int prev = INT_MAX;
        
        vector<int> v(s.size(), 0);
        for(int i=0;i<s.size();i++){
            if(s[i] == c){
                prev = i;
            }
            v[i] = abs(i - prev);
        }
        prev = INT_MAX;
        for(int i=s.size() - 1;i >= 0;i--){
            if(s[i] == c){
                prev = i;
            }
            v[i] = min(v[i], abs(i - prev));
        }
        return v;
    }
};