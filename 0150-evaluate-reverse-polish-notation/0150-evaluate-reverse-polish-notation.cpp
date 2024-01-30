class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it : tokens){
            if(it == "+" || it == "-" || it == "*" || it == "/" ){
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();
                
                int res = 0;
                if(it == "+"){
                    res = top2 + top1;
                }else if(it == "-"){
                    res = top2 - top1;
                }else if(it == "*"){
                    res = top2 * top1;
                }else{
                    res = top2 / top1;
                }
                st.push(res);
            }else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};