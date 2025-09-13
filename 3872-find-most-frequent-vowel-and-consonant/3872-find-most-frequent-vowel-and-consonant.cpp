class Solution {
public:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch]++;
        }
        int vowel = 0, consonant = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (is_vowel(ch)) {
                vowel = max(vowel, mp[ch]);
            } else {
                consonant = max(consonant, mp[ch]);
            }
        }
        return vowel + consonant;
    }
};