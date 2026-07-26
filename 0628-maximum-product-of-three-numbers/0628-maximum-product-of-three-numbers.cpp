class Solution {
public:
    int maximumProduct(vector<int>& A) {
        int a = -1001, b = a, c = b;    // max 3
        int x =  1001, y = x;           // min 2

        for (auto& n : A) {
            int pa = a, pb = b, px = x; // cache old values

            a = max(a, n);              // Update 1st max
            b = max(b, min(pa, n));     // Shift to 2nd max
            c = max(c, min(pb, n));     // Shift to 3rd max

            x = min(x, n);              // Update 1st min
            y = min(y, max(px, n));     // Shift to 2nd min
        }

        return max(a * b * c, a * x * y);
    }
};