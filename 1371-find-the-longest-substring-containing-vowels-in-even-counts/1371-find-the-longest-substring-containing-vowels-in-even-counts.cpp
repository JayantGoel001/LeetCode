class Solution {
public:
    int findTheLongestSubstring(string s) {
        int prefixXOR = 0;
        // Store the masks of all letters in an array.
        int characterMap[26] = {0};
        characterMap['a' - 'a'] = 1;
        characterMap['e' - 'a'] = 2;
        characterMap['i' - 'a'] = 4;
        characterMap['o' - 'a'] = 8;
        characterMap['u' - 'a'] = 16;
        // Initialize mp to store the previous index with this prefixXOR value.
        vector<int> mp(32, -1);
        int longestSubstring = 0;

        for (int i = 0; i < s.length(); i++) {
            // If the current character is a vowel, find it's prefix XOR and add
            // it in the map.
            prefixXOR ^= characterMap[s[i] - 'a'];
            if (mp[prefixXOR] == -1 and prefixXOR != 0) mp[prefixXOR] = i;

            // If the value of prefixXOR exists in the map, find the longest
            // subarray.
            longestSubstring = max(longestSubstring, i - mp[prefixXOR]);
        }

        return longestSubstring;
    }
};