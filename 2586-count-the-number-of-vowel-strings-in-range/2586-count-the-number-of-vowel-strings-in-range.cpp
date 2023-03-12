class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    bool isVowelString(string &word){
        return isVowel(word[0]) && isVowel(word[word.size() - 1]);
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for(int i=left;i<=right;i++){
            count += isVowelString(words[i]);
        }
        return count;
    }
};