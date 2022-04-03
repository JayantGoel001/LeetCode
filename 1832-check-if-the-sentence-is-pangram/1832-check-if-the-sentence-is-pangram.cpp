class Solution {
public:
    bool checkIfPangram(string sentence) {
        int ar[26] = {0};
        for(auto it : sentence){
            ar[it - 97]++;
        }
        for(int i=0;i<26;i++){
            if(ar[i] == 0){
                return false;
            }
        }
        return true;
    }
};