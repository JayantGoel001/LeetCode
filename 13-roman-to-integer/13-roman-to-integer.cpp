class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> symbol;
        symbol['I']=1;
        symbol['V']=5;
        symbol['X']=10;
        symbol['L']=50;
        symbol['C']=100;
        symbol['D']=500;
        symbol['M']=1000;
        int total = 0;
        int last = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(symbol[s[i]] >= last){
                total += symbol[s[i]];
            }else{
                total-= symbol[s[i]];
            }
            last = symbol[s[i]];
        }
        return total;
    }
};