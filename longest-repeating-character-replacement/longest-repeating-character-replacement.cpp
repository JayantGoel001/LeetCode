class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int count[26];
        for(int i=0;i<26;i++){
            count[i] = 0;
        }
        int start = 0;
        int maxi = 0;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            count[s[i]-'A']++;
            maxi = max(maxi,count[s[i] - 'A']);
            while(i + 1 - start > k + maxi){
                count[s[start++] - 'A']--;
            }
            maxLen = max(maxLen,i + 1 - start);
        }
        return maxLen;
    }
};