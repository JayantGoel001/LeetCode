class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> v(26, 0);
        for(auto it : brokenLetters){
            v[it - 'a']++;
        }
        
        string str = "";
        int count = 0;
        bool flag = true;
        
        for(auto it : text){
            if(it == ' '){
                count += flag;
                str = "";
                flag = true;
            }else{
                if(v[it - 'a'] != 0){
                    flag = false;
                }
            
                str += it;
            }
        }
        count += flag;
        return count;
    }
};