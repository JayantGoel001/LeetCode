class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int first = INT_MAX;
        int second = 0;
        while(s[second] != c){
            second++;
        }
        vector<int> v;
        for(int i=0;i<s.size();i++){
            if(s[i] == c){
                int start = i + 1;
                while(start < s.size() && s[start] != c){
                    start++;
                }
                first = i;
                if(start != s.size()){
                    second = start;
                }else{
                    second = INT_MAX;
                }
            }
            v.push_back(min(abs(i - first), abs(second - i)));
        }
        return v;
    }
};