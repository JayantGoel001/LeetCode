class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> st;
        for(auto it : s){
            if(st.find(it) != st.end()){
                return it;
            }
            st.insert(it);
        }
        return ' ';
    }
};