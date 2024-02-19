#define ll long long int
class Solution {
public:
    int power(ll x,int y){
        if(y == 0){
            return 1ll;
        } else{
            if(y % 2 == 0){
                return power(x * x, y/2);
            } else{
                return (ll)x * power(x * x, y/2);
            }
        }
    }
    bool isPowerOfTwo(int n) {
        return n > 0 && power(2, (int)log2(n)) == n;
    }
};