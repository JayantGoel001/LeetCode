#define pii pair<int,int>
class Solution {
public:
    int count = 0;
    pii getPal(string &s,int i,int j,int n){
        while(i>=0 && j < n && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        i++;
        return {i,j};
    }
    int countSubstrings(string s) {
        int size = s.size();
        pii maxi = {-1,-1};
        for(int i=0;i<size;i++){
            pii _1 = getPal(s,i,i,size);
            pii _2 = getPal(s,i,i+1,size);
            
            if(maxi.second - maxi.first < _1.second - _1.first ){
                maxi = _1;
            }
            if(maxi.second - maxi.first < _2.second - _2.first ){
                maxi = _2;
            }
        }
        return count;
    }
};