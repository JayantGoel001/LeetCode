class Solution {
public:
    int partitionString(string s) {
        int start = 0;
        vector<int> v(26, -1);
        int count = 1;
        for(int i=0;i<s.size();i++){
            if(v[s[i] - 'a'] >= start){
                count++;
                start = i;
            }
            v[s[i] - 'a'] = i;
        }
        return count;
    }
};