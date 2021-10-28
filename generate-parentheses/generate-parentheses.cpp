class Solution {
public:
    vector<string> v;
    void getAllPar(int n,int op,int cl,string str){
        if(op == n && cl == n){
            v.push_back(str);
        }else{
            if(op < n){
                getAllPar(n,op+1,cl,str + '(');
            }
            if(cl < op){
                getAllPar(n,op,cl+1,str + ')');
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        int op = 0;
        int cl = 0;
        string str = "";
        
        getAllPar(n,op,cl,str);
        
        return v;
    }
};