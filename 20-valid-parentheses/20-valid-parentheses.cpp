class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(auto it : s){
            if(it == '(' || it == '{' || it == '['){
                st.push(it);
            }else{
                if(!st.empty()){
                    char top = st.top();
                    st.pop();
                    
                    if(!((it == ')' && top == '(') || (it == '}' && top == '{') || (it == ']' && top == '['))){
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};