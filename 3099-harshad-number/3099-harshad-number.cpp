namespace {
constexpr auto harshadNumber = []() {
    array<signed char, 101> ans = {};
    for (int x = 1; x <= 100; ++x) {
        const int s = x % 10 + (x / 10) % 10 + x / 100;
        ans[x] = x % s ? -1 : s;
    }
    return ans;    
}();
}  // namespace

class Solution {
public:
    static int sumOfTheDigitsOfHarshadNumber(int x) {
        return harshadNumber[x];
    }
};