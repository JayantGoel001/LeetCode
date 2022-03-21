class Solution {
public:
    vector<int> partitionLabels(string s) {
        int mp[26];
        
        int size = s.size();
        for(int i=0;i<size;i++){
            mp[s[i]-'a'] = i;
        }
        int anchor = 0;
        vector<int> v;
        int maxi = 0;
        for(int i=0;i<size;i++){
            maxi = max(maxi,mp[s[i] - 'a']);
            if(maxi == i){
                v.push_back(i - anchor + 1);
                anchor = i+1;
            }
        }
        return v;
    }
};