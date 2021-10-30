#define pii pair<int,int>
class Solution {
public:
    int prime = 10000007;
    vector<int> power;
    string checkString(string &s,int len){
         if(len == 0){
             return "";
         }
        int n = s.size(), curr = 0;
        unordered_map<int, vector<int>> hash;
        
        
        for(int i = 0; i < len; i++) {
            curr = (curr * 26 + (s[i]-'a')) % prime;
        }
        hash[curr] = {0};
        
        for(int i = len; i < n; i++) {
            
            curr = ((curr - power[len-1] * (s[i-len]-'a')) % prime + prime) % prime;
            curr = (curr * 26 + (s[i]-'a')) % prime;
            
            
            if(hash.find(curr) == hash.end()){
                hash[curr] = {i-len+1};
            }else {
                for(int index: hash[curr]) {
                    if(s.substr(index, len) == s.substr(i-len+1, len)){
                        return s.substr(index, len);
                    }
                }
                hash[curr].push_back({i-len+1});
            }
        }
        return ""; 
    }
    string longestDupSubstring(string s) {
        int n = s.size();
        int l = 1, r = n-1;
        power = vector<int>(n);
        for(int i = 0; i < n; i++){
            power[i] = (i == 0) ? 1 : (power[i-1] * 26) % prime;
        }
        
        string res;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            string dup = checkString(s, mid);
            
            if((int)dup.size() > (int)res.size()) {
                res = dup;
                l = mid+1;
            } else{
                r = mid-1;
            }
        }
        return res;
    }
};