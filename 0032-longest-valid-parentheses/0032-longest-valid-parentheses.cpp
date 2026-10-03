class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi = 0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(st.empty()){
                    continue;
                }
                st.pop();
                
                if(st.empty()){
                    st.push(i);
                }else{
                    maxi = max(maxi,i - st.top());
                }
            }
        }
        return maxi;
    }
};