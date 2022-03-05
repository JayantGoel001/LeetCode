class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int i;
        for(i=0;i<min(word1.size(),word2.size());i++){
            res += word1[i];
            res += word2[i];
        }
        while(i < word1.size()){
            res += word1[i++];
        }
        while(i < word2.size()){
            res += word2[i++];
        }
        return res;
    }
};