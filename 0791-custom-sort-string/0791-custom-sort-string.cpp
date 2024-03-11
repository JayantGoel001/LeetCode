class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> v(26);
        for(int i=0;i<order.size();i++){
            v[order[i] - 'a'] = i;
        }
        
        sort(s.begin(), s.end(), [v](const char &a, const char &b) -> bool{
            return v[a - 'a'] < v[b - 'a'];
        });
        
        return s;
    }
};