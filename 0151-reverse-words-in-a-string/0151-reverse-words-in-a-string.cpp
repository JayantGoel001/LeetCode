class Solution {
public:
    void reverseEachWord(string &str) {
        int start = 0;
        int i = 0;
        while(i < str.size() && str[i] == ' ') i++;

        while(i < str.size()) {
            int x = start;
            while(i < str.size() && str[i] != ' ') str[start++] = str[i++];
            reverse(str.begin() + x, str.begin() + start);

            while(i < str.size() && str[i] == ' ') i++;

            if (i < str.size()) str[start++] = ' ';
        }
        str.resize(start);
    }
    string reverseWords(string s) {
        reverseEachWord(s);
        reverse(s.begin(), s.end());

        return s;
    }
};