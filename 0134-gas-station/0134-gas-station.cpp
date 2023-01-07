class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int start = 0;
        int end = gas.size() - 1;
        
        while(start <= end){
            if(sum + gas[start] - cost[start] >= 0){
                sum += (gas[start] - cost[start]);
                start++;
            }else{
                sum += (gas[end] - cost[end]);
                end--;
            }
        }
        return sum < 0 ? -1 : (end + 1)%gas.size();
    }
};