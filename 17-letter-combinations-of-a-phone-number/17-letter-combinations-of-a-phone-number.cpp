class Solution {
public:
    vector<string> v;
    void generateComb(string &digits,unordered_map<char,vector<char>> &mp,int x,string str){
        if(digits.size() == x){
            if(str != ""){
                v.push_back(str);
            }
        }else{
            for(auto it : mp[digits[x]]){
                generateComb(digits,mp,x+1,str + it);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<char>> mp;
        string str = "";
        
        mp['2'] = {'a','b','c'};
        mp['3'] = {'d','e','f'};
        mp['4'] = {'g','h','i'};
        mp['5'] = {'j','k','l'};
        mp['6'] = {'m','n','o'};
        mp['7'] = {'p','q','r','s'};
        mp['8'] = {'t','u','v'};
        mp['9'] = {'w','x','y','z'};
        
        generateComb(digits,mp,0,str);
        
        return v;
    }
};