class Solution {
public:
    vector<string> cellsInRange(string s) {
        int i = s[1] - '0';
        int n = s[4] - '0';
        char j = s[0];
        char m = s[3];
        
        vector<string> v;
        while(j <= m){
            int x = i;
            while(x <= n){
                string str(1,j);
                str.append(to_string(x));

                v.push_back(str);
                x++;
            }
            j++;
        }
        return v;
    }
};