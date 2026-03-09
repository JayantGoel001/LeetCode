class Solution {
public:
    int GCD(int x, int y) {
        if(y == 0) return x;

        return GCD(y, x % y);
    }
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        int gcd = GCD(str1.size(), str2.size());

        return str1.substr(0, gcd);
    }
};