class Solution {
public:
    int partitionString(string s) {
        int start = 0;
        vector<bool> v(26, false);
        int count = 1;
        for(int i=0;i<s.size();i++){
            if(v[s[i] - 'a']){
                while(start < i){
                    v[s[start++] - 'a'] = false;
                }
                count++;
            }
            v[s[i] - 'a'] = true;
        }
        return count;
    }
};