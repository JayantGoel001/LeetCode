class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int left = 0;
        int count = 0;
        while(numBottles){
            count += numBottles;
            
            int num = (left + numBottles) / numExchange;
            
            left = (left + numBottles) % numExchange;
            
            numBottles = num;
        }
        return count;
    }
};