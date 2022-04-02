#define ll long long
class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        vector<int> front(n,0),back(n,0);
        for (int i = 1; i < n; i++) {
            front[i] = front[i - 1] + (s[i - 1] == '1');
        }

        for (int i = n - 2; i >= 0; i--) {
            back[i] = back[i + 1] + (s[i + 1] == '1');
        }

        ll ans = 0;
        for (int i = 1; i < n-1; i++) {
            if (s[i] == '0') {
                ans += (ll) front[i] * back[i];
            }
            else{
                ans += (ll) (i - front[i]) * (n - i - back[i] - 1);
            }
        }
        return ans;
    }
};