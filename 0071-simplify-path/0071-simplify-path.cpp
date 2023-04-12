class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string str = "";
        for(auto it : path){
            if(it == '/'){
                if(str == ".."){
                    if(!st.empty()) {
                        st.pop();
                    }
                }else if(str != "." && str != ""){
                    st.push(str);
                }
                str = "";
            }else{
                str += it;
            }
        }
        if(str == ".."){
            if(!st.empty()) {
                st.pop();
            }
        }else if(str != "." && str != ""){
            st.push(str);
        }
        
        str = "";
        while(!st.empty()){
            str = "/" + st.top() + str;
            st.pop();
        }
        return str == "" ? "/" : str;
    }
};