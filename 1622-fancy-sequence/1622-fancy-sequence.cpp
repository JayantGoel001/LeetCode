class Fancy {
private:
    static constexpr int mod = 1000000007;
    vector<int> v;
    int a, b;

public:
    Fancy() : a(1), b(0) {}

    // fast exponentiation
    int quickmul(int x, int y) {
        int ret = 1;
        int cur = x;
        while (y) {
            if (y & 1) {
                ret = (long long)ret * cur % mod;
            }
            cur = (long long)cur * cur % mod;
            y >>= 1;
        }
        return ret;
    }

    // multiplicative inverse
    int inv(int x) { return quickmul(x, mod - 2); }

    void append(int val) {
        v.push_back((long long)((val - b + mod) % mod) * inv(a) % mod);
    }

    void addAll(int inc) { b = (b + inc) % mod; }

    void multAll(int m) {
        a = (long long)a * m % mod;
        b = (long long)b * m % mod;
    }

    int getIndex(int idx) {
        if (idx >= v.size()) {
            return -1;
        }
        int ans = ((long long)a * v[idx] % mod + b) % mod;
        return ans;
    }
};