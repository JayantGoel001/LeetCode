class Solution {
public:
    int minSteps(string s, string t) {
        int ar[26] = {0};
        for(auto it : s){
            ar[it - 'a']++;
        }
        for(auto it : t){
            ar[it - 'a']--;
        }
        int count = 0;
        for(int i=0;i<26;i++){
            count += abs(ar[i]);
        }
        return count;
    }
};