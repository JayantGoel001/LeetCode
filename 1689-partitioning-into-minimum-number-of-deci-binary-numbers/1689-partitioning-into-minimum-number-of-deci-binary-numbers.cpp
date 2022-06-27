class Solution {
public:
    int minPartitions(string n) {
        int maxi = 0;
        
        for(auto it : n){
            maxi = max(maxi,it - '0');
        }
        return maxi;
    }
};