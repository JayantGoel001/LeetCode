class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        vector<int> mp1(26, 0), mp2(26, 0);
        for(auto it : word1) mp1[it - 'a']++;
        for(auto it : word2) mp2[it - 'a']++;

        for(int i=0;i<26;i++) {
            if ((mp1[i] > 0) ^ (mp2[i] > 0)) return false;
        }
        sort(mp1.begin(), mp1.end());
        sort(mp2.begin(), mp2.end());
        for(int i=0;i<26;i++) {
            if (mp1[i] != mp2[i]) return false;
        }

        return true;
    }
};