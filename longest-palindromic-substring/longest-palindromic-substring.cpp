#define pii pair<int,int> 
class Solution {
public:
    pii getPal(string &s,int start,int end){
        int size = s.size();
        while(start>=0 && end <size && s[start] == s[end]){
            start--;
            end++;
        }
        start++;
        return {start,end};
    }
    string longestPalindrome(string &s) {
        pii maxi = {0,1};
        
        int size = s.size();
        pii res1 = maxi;
        pii res2 = maxi;
        
        for(int i=0;i<size;i++){
            res1 = getPal(s,i-1,i);
            res2 = getPal(s,i-1,i-1);
            if(res1.second - res1.first >= maxi.second - maxi.first){
                maxi = res1;
            }
            if(res2.second - res2.first >= maxi.second - maxi.first){
                maxi = res2;
            }
            
        }
        return s.substr(maxi.first,maxi.second - maxi.first);
    }
};