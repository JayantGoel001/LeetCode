class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        stack<int> st;
        
        for(auto it : s){
            if(it == '('){
                st.push(it);
            }else if(it == ')'){
                maxi = max(maxi,(int)st.size());
                if(st.empty()){
                    continue;
                }
                st.pop();
            }
        }
        return maxi;
    }
};