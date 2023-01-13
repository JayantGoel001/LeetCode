class Solution {
public:
    int getNumber(string &str){
        int num = 0;
        for(auto it : str){
            num = num * 10 + (it - 'a');
        }
        return num;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int first = getNumber(firstWord);
        int second = getNumber(secondWord);
        int third = getNumber(targetWord);
        
        return first + second == third;
    }
};