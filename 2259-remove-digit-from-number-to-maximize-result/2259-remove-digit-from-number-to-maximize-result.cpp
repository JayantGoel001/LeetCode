class Solution {
public:
    string removeDigit(string number, char digit) {
        string maxi = "";
        for(int i=0;i<number.size();i++){
            if(number[i] == digit){
                string str = number.substr(0,i);
                str.append(number.substr(i + 1,number.size() - i - 1));
                if(maxi.compare(str) < 0){
                    maxi = str;   
                }
            }
        }
        return maxi;
    }
};