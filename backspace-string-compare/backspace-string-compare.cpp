class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1,st2;
        
        for(auto it : s){
            if(it == '#'){
                if(!st1.empty()){
                    st1.pop();
                }
            }else{
                st1.push(it);
            }
        }
        for(auto it : t){
            if(it == '#'){
                if(!st2.empty()){
                    st2.pop();
                }
            }else{
                st2.push(it);
            }
        }
        while(!st1.empty() && !st2.empty()){
            if(st1.top() != st2.top()){
                return false;
            }
            st1.pop();
            st2.pop();
        }
        return st1.size() == st2.size();
    }
};