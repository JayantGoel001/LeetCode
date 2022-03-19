class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0;
        for(auto it : nums){
            pq.push(it);
            sum += it;
        }
        int count = 0;
        double reduced = 0;
        while(!pq.empty()){
            double top = pq.top();
            pq.pop();
            reduced += top/2.0;
            
            count++;
            if(reduced >= sum/2.0){
                break;
            }
            pq.push(top/2.0);
        }
        return count;
    }
};