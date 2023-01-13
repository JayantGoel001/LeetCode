class Solution {
public:
    string generateTheString(int n) {
        string str = "";
        for(int i=0;i<n-1;i++){
            str += 'a';
        }
        str += n%2 ? "a" : "b";
        return str;
    }
};