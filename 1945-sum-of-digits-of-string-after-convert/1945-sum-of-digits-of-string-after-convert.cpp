#define ll long long
class Solution {
public:
    int getLucky(string s, int k) {
        ll sum = 0;
        for(auto it : s){
            int num = (it - 'a' + 1);
            while(num){
                sum += (ll)(num%10);
                num/=10;
            }
        }
        while(--k){
            ll s = 0;
            while(sum){
                s += (ll)sum%10;
                sum/=10;
            }
            sum = s;
        }
        return (int)sum;
    }
};