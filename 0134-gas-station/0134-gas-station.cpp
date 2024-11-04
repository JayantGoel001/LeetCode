class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int start = 0;
        for(int i=0;i<gas.size();i++) {
            gas[i] -= cost[i];
            sum += gas[i];
        }

        if (sum < 0) {
            return -1;
        }
        
        sum = 0;
        for(int i=0;i<gas.size();i++) {
            sum += gas[i];
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }

        return start;
    }
};