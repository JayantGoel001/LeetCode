class Solution {
public:
    string convert(string s, int n) {
        if(n == 1){
            return s;
        }
        string str = "";
        for(int i = 0;i<n;i++){
            int j = i;
            while(j < s.size()){
                str += s[j];
                j += (2 * n - 2);
                
                if(i != 0 && i != n - 1 && j - 2 * i < s.size()){
                    str += s[j - 2 * i];
                }
            }
        }
        return str;
    }
};