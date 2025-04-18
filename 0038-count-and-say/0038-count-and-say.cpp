class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        int c;
        string str;
        for(int i=1;i<n;i++){
            c = 1;
            str = "";
            int size = res.size();
            for(int j=0;j<size-1;j++){
                if(res[j] == res[j+1]){
                    c++;
                }else{
                    str.append(to_string(c));
                    str += res[j];
                    c = 1;
                }
            }
            str.append(to_string(c));
            str += res[size-1];
            
            res = str;
        }
        return res;
    }
};