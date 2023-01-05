class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int mini = INT_MAX;
        for(int i=0;i<words.size();i++){
            if(words[i] == target){
                mini = min({mini, (int)abs(i - startIndex), (int)(words.size() - abs(startIndex - i))});
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};