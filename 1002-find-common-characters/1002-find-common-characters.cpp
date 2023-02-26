class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> v0(26, INT_MAX);
        for(auto word : words){
            vector<int> v1(26, 0), v(26, 0);
            
            for(auto it : word){
                v1[it - 'a']++;
            }
            for(int i=0;i<26;i++){
                v[i] = min(v0[i], v1[i]);
            }
            v0 = v;
        }
        
        vector<string> v;
        for(int i=0;i<26;i++){
            while(v0[i]){
                string str(1, i + 'a');
                v.push_back(str);
                v0[i]--;
            }
        }
        return v;
    }
};