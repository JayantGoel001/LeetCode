class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        
        for(auto it : s){
            if(it == '(' || it == '{' || it == '['){
                st.push(mp[it]);
            }else{
                if(st.empty() || st.top() != it){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};