class Solution {
public:
        bool isOneBitCharacter(vector<int>& bits) {
        int count_1 = 0;
        for (int i = (int) bits.size() - 2; i >= 0 && bits[i] == 1; i--) count_1++;
        return (count_1 % 2 == 0);
    }

};