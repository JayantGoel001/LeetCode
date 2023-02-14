class Solution {
public:
    string addBinary(string &a, string &b) {
        stack<int> st1,st2,st3;
        
        for(auto it : a){
            st1.push((it - '0'));
        }
        for(auto it : b){
            st2.push((it - '0'));
        }
        
        string res = "";
        int carry = 0;
        while(!st1.empty() && !st2.empty()){
            int top1 = st1.top();
            int top2 = st2.top();
            
            if(top1 == 1 && top2 == 1){
                if(carry){
                    res = '1' + res;
                }else{
                    res = '0' + res;
                }
                carry = 1;
            }else if(top1 == 1 || top2 == 1){
                if(carry){
                    res = '0' + res;
                }else{
                    res = '1' + res;
                }
            }else{
                if(carry){
                    res = '1' + res;
                }else{
                    res = '0' + res;
                }
                carry = 0;
            }
            st1.pop();
            st2.pop();
        }
        while(!st1.empty()){
            int top = st1.top();
            if(top == 1){
                if(carry){
                    res = "0" + res;
                }else{
                    res = "1" + res;
                }
            }else{
                if(carry){
                    res = "1" + res;
                }else{
                    res = "0" + res;
                }
                carry = 0;
            }
            
            st1.pop();
        }
        
        while(!st2.empty()){
            int top = st2.top();
            if(top == 1){
                if(carry){
                    res = "0" + res;
                }else{
                    res = "1" + res;
                }
            }else{
                if(carry){
                    res = "1" + res;
                }else{
                    res = "0" + res;
                }
                carry = 0;
            }
            
            st2.pop();
        }
        if(carry){
            res ="1" + res;
        }
        
        return res;
    }
};