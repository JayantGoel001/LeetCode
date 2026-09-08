class Solution {
public:
    int countCommas(int n) { 
        return max(n - 999, 0); 
    }
};