class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int result = 0;

        int targetSetBitsCount = __builtin_popcount(num2);
        int setBitsCount = 0;
        int currentBit = 31;  // Start from the most significant bit.

        // While x has fewer set bits than num2
        while (setBitsCount < targetSetBitsCount) {
            // If the current bit of num1 is set or we must set all remaining
            // bits in result
            if (isSet(num1, currentBit) ||
                (targetSetBitsCount - setBitsCount > currentBit)) {
                setBit(result, currentBit);
                setBitsCount++;
            }
            currentBit--;  // Move to the next bit.
        }

        return result;
    }

private:
    // Helper function to check if the given bit position in x is set (1).
    bool isSet(int x, int bit) { return x & (1 << bit); }

    // Helper function to set the given bit position in x to 1.
    void setBit(int &x, int bit) { x |= (1 << bit); }
};