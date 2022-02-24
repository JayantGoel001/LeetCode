class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> v(n,0);
        
        int start = 0;
        int maxi = 0;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,++v[s[i] - 'A']);
            while(i - start + 1 > maxi + k){
                v[s[start++] - 'A']--;
            }
            maxLen = max(maxLen,i - start + 1);
        }
        return maxLen;
    }
};