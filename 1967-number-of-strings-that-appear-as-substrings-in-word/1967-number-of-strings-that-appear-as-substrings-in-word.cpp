class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(auto it : patterns){
            count += word.find(it) != string::npos;
        }
        return count;
    }
};