class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int mini = INT_MAX;
        for(int i=0;i<words.size();i++){
            if(words[i] == target){
                mini = min({mini, (int)((i - startIndex + words.size())%words.size()), (int)((startIndex - i + words.size())%words.size())});
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};