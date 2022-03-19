#define ll long long int
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        ll count0 = 0,count1 = 0;
        ll res = 0;
        for(auto it : text){
            if(it == pattern[1]){
                res += count0;
                count1++;
            }
            if(it == pattern[0]){
                count0++;
            }
        }
        return res + max(count0,count1);
    }
};