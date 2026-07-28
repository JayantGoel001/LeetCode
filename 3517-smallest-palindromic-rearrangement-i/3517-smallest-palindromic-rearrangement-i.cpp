class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int bucket[26] = {0};

        for (int i = 0; i < n / 2; i++) {
            bucket[s[i] - 'a']++;
        }

        int left = 0;
        int right = n - 1;

        for (int i = 0; i < 26; i++) {
            while (bucket[i] > 0) {
                char c = i + 'a';
                s[left++] = c;
                s[right--] = c;
                bucket[i]--;
            }
        }

        return s;
    }
};