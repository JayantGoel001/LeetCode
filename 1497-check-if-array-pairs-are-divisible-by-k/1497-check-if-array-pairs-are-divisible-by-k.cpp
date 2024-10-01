class Solution {
public:
    // Custom comparator to sort based on mod values.
    struct Comparator {
        int k;
        Comparator(int k) { this->k = k; }
        bool operator()(int i, int j) {
            return (k + i % k) % k < (k + j % k) % k;
        }
    };

    bool canArrange(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end(), Comparator(k));

        // Assign the pairs with modulo 0 first.
        int start = 0, end = arr.size() - 1;
        while (start < end) {
            if (arr[start] % k != 0) break;
            if (arr[start + 1] % k != 0) return false;
            start = start + 2;
        }

        // Now, pick one element from the beginning and one element from the
        // end.
        while (start < end) {
            if ((arr[start] + arr[end]) % k != 0) return false;
            start++;
            end--;
        }
        return true;
    }
};