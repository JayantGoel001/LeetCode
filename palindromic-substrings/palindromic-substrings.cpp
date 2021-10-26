class Solution {
public:
    int count = 0;
    void getPal(string &s,int i,int j,int n){
        while(i>=0 && j < n && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        i++;
    }
    int countSubstrings(string s) {
        int size = s.size();
        for(int i=0;i<size;i++){
            getPal(s,i,i,size);
            getPal(s,i,i+1,size);
        }
        return count;
    }
};