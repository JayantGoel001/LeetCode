class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool ar[26] = {false};
        for(auto it : allowed){
            ar[it - 'a'] = true;
        }
        int count = 0;
        for(auto word : words){
            bool flag = true;
            for(auto it : word){
                if(!ar[it - 'a']){
                    flag = false;
                    break;
                }
            }
            count += flag;
        }
        return count;
    }
};