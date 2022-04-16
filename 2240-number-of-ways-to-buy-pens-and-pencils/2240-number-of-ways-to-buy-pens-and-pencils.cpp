#define ll long long int
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        ll count = 0;
        do{
            count += (total/cost2 + 1);
            total -= cost1;
        }while(total >= 0);
        
        return count;
    }
};