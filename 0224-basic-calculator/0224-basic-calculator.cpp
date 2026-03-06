class Solution {
public:
    int calculate(string s) {
        stack<int> op;
        op.push(1);
        int sign=1;
        int n=s.size();
        int i=0, ret=0;
        while(i<n){
            if(s[i]==' ')
                i++;
            else if(s[i]=='+'){
                sign=op.top();
                i++;
            }else if(s[i]=='-'){
                sign=-op.top();
                i++;
            }else if(s[i]=='('){
                op.push(sign);
                i++;
            }else if(s[i]==')'){
                op.pop();
                i++;
            }else{
                long num=0;
                while(i<n && s[i]>='0' && s[i]<='9'){
                    num=num*10+s[i]-'0';
                    i++;
                }
                ret+=sign*num;
            }
        }
        return ret;
    }
};