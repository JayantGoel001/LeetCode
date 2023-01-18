class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26, 0);
        
        int maxSum = 0;
        int start = 0;
        int maxLen = 0;
        
        for(int i=0;i<s.size();i++){
            maxSum = max(maxSum, ++v[s[i] - 'A']);
            
            while(i - start >= k + maxSum){
                v[s[start++] - 'A']--;
            }
            
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};