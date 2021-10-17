class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = "";
        string str2 = "";
        
        for(auto it : word1){
            str1.append(it);
        }
        for(auto it : word2){
            str2.append(it);
        }
        return str1 == str2;
    }
};