class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        
        while(k-- && !pq.empty() && pq.top() > 1){
            int top = pq.top();
            pq.pop();
            
            if(top > 1){
                pq.push(floor(sqrt(top)));
            }
        }
        long long sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};