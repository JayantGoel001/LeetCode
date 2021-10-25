// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int i = rand7();
        
        while(i == 7){
            i = rand7();
        }
        int j = rand7();
        
        while(j == 6 || j == 7){
            j = rand7();
        }
        
        return i%2? j : j + 5;
    }
};