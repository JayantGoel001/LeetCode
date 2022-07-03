class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> ar(26,-1);
        int k = 0;
        for(int i=0;i<key.size();i++){
            if(key[i] != ' ' && ar[key[i] - 'a'] == -1){
                ar[key[i] - 'a'] = k++;
            }
        }
        string str = "";
        for(auto it : message){
            if(it == ' '){
                str += ' ';
            }else{
                str += (char)(ar[it - 'a'] + 'a');
            }
        }
        return str;
    }
};