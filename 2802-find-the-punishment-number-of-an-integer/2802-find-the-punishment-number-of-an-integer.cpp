class Solution {
public:
    bool CanPartition(int num, int target) {
        // Invalid partition found
        if (target < 0 || num < target) {
            return false;
        }

        // Valid partition found
        if (num == target) {
            return true;
        }

        // Recursively check all partitions for a valid partition
        return CanPartition(num / 10, target - num % 10) ||
               CanPartition(num / 100, target - num % 100) ||
               CanPartition(num / 1000, target - num % 1000);
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;

        // Iterate through numbers in range [1, n]
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;

            // Check if valid partition can be found and add squared number if
            // so
            if (CanPartition(squareNum, currentNum)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
};