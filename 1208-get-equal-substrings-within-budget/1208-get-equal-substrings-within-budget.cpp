class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int N = s.size();
        
        int maxLen = 0;
        // Starting index of the current substring
        int start = 0;
        // Cost of converting the current substring in s to t
        int currCost = 0;
        
        for (int i = 0; i < N; i++) {
            // Add the current index to the substring
            currCost += abs(s[i] - t[i]);
            
            // Remove the indices from the left end till the cost becomes less than allowed
            while (currCost > maxCost) {
                currCost -= abs(s[start] - t[start]);
                start++;
            }
            
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
};