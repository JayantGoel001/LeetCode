class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st;
        for(auto it : paths){
            st.insert(it[0]);
        }
        for(auto it : paths){
            if(st.find(it[1]) == st.end()){
                return it[1];
            }
        }
        return "";
    }
};