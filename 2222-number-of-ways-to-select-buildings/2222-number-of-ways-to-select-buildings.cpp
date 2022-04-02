#define ll long long int
class Solution {
public:
    long long numberOfWays(string s) {
        int one = 0;
        int zero = 0;
        for(auto it : s){
            if(it == '1'){
                one++;
            }else{
                zero++;
            }
        }
        int o = 0;
        int z = 0;
        ll count = 0;
        for(auto it : s){
            if(it == '0'){
                count += (ll)one * o;
                z++;
                zero--;
            }else{
                count += (ll)zero * z;
                o++;
                one--;
            }
        }
        return count;
    }
};