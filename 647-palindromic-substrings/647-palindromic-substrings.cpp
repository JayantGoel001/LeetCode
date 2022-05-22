class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0;i<s.size();i++){
            count += getLP(s,i,i);
            count += getLP(s,i,i + 1);
        }
        return count;
    }
    int getLP(string &str,int i,int j){
        int count = 0;
        while(i>=0 && j < str.size() && str[i] == str[j]){
            i--;
            j++;
            count++;
        }
        return count;
    }
};