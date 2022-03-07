class Solution {
public:
    bool isPal(string &str){
        int i = 0;
        int j = str.size()-1;
        
        while(i <= j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
        
    }
    string firstPalindrome(vector<string>& words) {
        for(auto it : words){
            if(isPal(it)){
                return it;
            }
        }
        return "";
    }
};