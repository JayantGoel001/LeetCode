class Solution {
public:
    vector<vector<string>> v;
    bool isPalindrome(string &s,int start,int end){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void generateComb(string &s,vector<string> &temp,int start){
        if(start == s.size()){
            v.push_back(temp);
        }else{
            for(int i=start;i<s.size();i++){
                if(isPalindrome(s,start,i)){
                    temp.push_back(s.substr(start,i - start + 1));
                    
                    generateComb(s,temp,i+1);
                    temp.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        
        generateComb(s,temp,0);
        
        return v;
    }
};