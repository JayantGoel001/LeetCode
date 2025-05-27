class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total = n * (n + 1) / 2;
        int num = n / m;
        int totalM = m * (num * (num + 1) / 2);
        
        return total - 2 * totalM;
    }
};