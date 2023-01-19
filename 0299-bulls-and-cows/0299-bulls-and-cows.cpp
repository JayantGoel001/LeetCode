class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> vs(10, 0), vg(10, 0);
        int b = 0;
        int c = 0;
        
        for(int i=0;i<secret.size();i++){
            if(secret[i] == guess[i]){
                b++;
            }else{
                vs[secret[i] - '0']++;
                vg[guess[i] - '0']++;
            }
        }
        for(int i=0;i<10;i++){
            c += min(vs[i], vg[i]);
        }
        
        string str = "";
        str += to_string(b);
        str += 'A';
        str += to_string(c);
        str += 'B';
        
        return str;
    }
};