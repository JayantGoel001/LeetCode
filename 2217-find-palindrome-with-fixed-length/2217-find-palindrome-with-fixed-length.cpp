#define ll long long
class Solution {
public:
    ll power(ll x,int y){
        if(y == 0){
            return 1ll;
        }else{
            if(y%2 == 0){
                return (ll)power(x * x,y/2);
            }else{
                return (ll)x * power(x * x,(y-1)/2);
            }
        }
    }
    int getLength(ll x){
        if(x == 0){
            return 1;
        }
        int count = 0;
        while(x!=0){
            count++;
            x/=10;
        }
        return count;
    }
    ll getReverse(ll x){
        ll sum = 0;
        while(x!=0){
            sum = sum * 10 + x%10;
            x/=10;
        }
        return sum;
    }
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<ll> v;
        if(intLength == 1){
            for(auto it : queries){
                if(it <= 9){
                    v.push_back(it);
                }else{
                    v.push_back(-1);
                }
            }
            return v;
        }
        
        int n = intLength/2;
        ll initial = power(10ll,n - 1);
        if(intLength%2 == 0){
            for(auto it : queries){
                ll x = initial + it - 1;
                int len = getLength(x);
                if(len != n){
                    v.push_back(-1);
                }else{
                    string str = to_string(x);
                    string rev = str;
                    reverse(rev.begin(),rev.end());
                    v.push_back(stol(str + rev));
                }
            }
        }else{
            for(auto it : queries){
                ll mid = (it - 1)%10;
                ll x = initial + (ll)(it - 1)/10;
                int len = getLength(x);
                if(len != n){
                    v.push_back(-1);
                }else{
                    string str = to_string(x);
                    string ms = to_string(mid);
                    string rev = str;
                    reverse(rev.begin(),rev.end());
                    v.push_back(stol(str + ms + rev));
                }
            }
        }
        return v;
    }
};