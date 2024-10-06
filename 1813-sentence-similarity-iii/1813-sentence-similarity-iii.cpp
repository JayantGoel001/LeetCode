class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        // Convert sentences to lists of words
        stringstream ss1(s1), ss2(s2);
        string word;
        vector<string> s1Words, s2Words;
        while (ss1 >> word) s1Words.push_back(word);
        while (ss2 >> word) s2Words.push_back(word);

        int start = 0, ends1 = s1Words.size() - 1, ends2 = s2Words.size() - 1;

        // If words in s1 are more than s2, swap them and return the answer.
        if (s1Words.size() > s2Words.size()) return areSentencesSimilar(s2, s1);

        // Find the maximum words matching from the beginning.
        while (start < s1Words.size() && s1Words[start] == s2Words[start])
            ++start;

        // Find the maximum words matching in the end.
        while (ends1 >= 0 && s1Words[ends1] == s2Words[ends2]) {
            --ends1;
            --ends2;
        }

        // If ends1 index is less than start, then sentence is similar.
        return ends1 < start;
    }
};