class Solution {
public:
    int minTimeToType(string word) {
        int prev = 0;
        
        int count = word.size();
        for(auto it : word){
            count += min(abs(it - 'a' - prev), 26 - abs(it - 'a' - prev));
            prev = it - 'a';
        }
        return count;
    }
};