class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int subSum = INT_MAX;
        int start = 0;
        for(int i=0;i<gas.size();i++){
            sum += (gas[i] - cost[i]);
            if(subSum > sum){
                subSum = sum;
                start = i;
            }
        }
        return sum < 0 ? -1 : (start + 1)%gas.size();
    }
};