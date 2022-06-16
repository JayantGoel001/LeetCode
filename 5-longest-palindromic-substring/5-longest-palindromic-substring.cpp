#define pii pair<int,int>
class Solution {
public:
    string longestPalindrome(string s) {
        pii maxi = {0, 0};
        for(int i=0;i<s.size();i++){
            pii p1 = getLP(s,i,i);
            pii p2 = getLP(s,i,i + 1);
            
            if(p1.second - p1.first > maxi.second - maxi.first){
                maxi = p1;
            }
            if(p2.second - p2.first > maxi.second - maxi.first){
                maxi = p2;
            }
        }
        return s.substr(maxi.first,maxi.second - maxi.first);
    }
    
    pii getLP(string &str,int i,int j){
        while(i>=0 && j < str.size() && str[i] == str[j]){
            i--;
            j++;
        }
        return {i+1,j};
    }
};