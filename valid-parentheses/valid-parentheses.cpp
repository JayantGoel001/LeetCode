class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it : s){
            if(it == '(' || it == '{' || it == '['){
                st.push(it);
            }else{
                if(st.empty()){
                    return false;
                }else{
                    char top = st.top();
                    st.pop();
                    if(!((top == '(' && it == ')') || (top == '{' && it == '}') || (top == '[' && it == ']'))){
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};