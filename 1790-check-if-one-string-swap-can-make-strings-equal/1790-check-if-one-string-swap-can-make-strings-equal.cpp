class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        int n = s1.size();
        unordered_map<char,int> mp;
        
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]){
                count++;
            }
            mp[s1[i]]++;
            mp[s2[i]]--;
        }
        int sum = 0;
        for(auto it : mp){
            sum += abs(it.second);
        }
        return (count == 0 || count == 2) && sum == 0;
    }
};