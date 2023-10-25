class Solution {
public:
    int recursion(int n, int k) {
        // First row will only have one symbol '0'.
        if (n == 1) {
            return 0;
        }

        int totalElements = pow(2, (n - 1));
        int halfElements = totalElements / 2;

        // If the target is present in the right half, we switch to the respective left half symbol.
        if (k > halfElements) {
            return 1 - kthGrammar(n, k - halfElements);
        }

        // Otherwise, we switch to the previous row.
        return recursion(n - 1, k);
    }

    int kthGrammar(int n, int k) {
        return recursion(n, k);
    }
};