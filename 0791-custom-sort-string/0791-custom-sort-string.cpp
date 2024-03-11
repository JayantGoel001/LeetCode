class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> v(26, 0);
        
        for(auto it: s){
            v[it - 'a']++;
        }
        string result = "";
        for(auto it : order){
            while(v[it - 'a']-- > 0){
                result += it;
            }
        }
        for(int i=0;i<v.size();i++){
            while(v[i]-- > 0){
                result += (i + 'a');
            }
        }
        cout<<result;
        return result;
    }
};