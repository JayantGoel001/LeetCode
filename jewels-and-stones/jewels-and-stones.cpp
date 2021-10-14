class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for(auto it : jewels){
            for(auto stone : stones){
                if(it == stone){
                    count++;
                }
            }
        }
        return count;
    }
};