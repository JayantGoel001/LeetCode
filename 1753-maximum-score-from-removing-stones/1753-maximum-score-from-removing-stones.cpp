class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int count = 0;
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        while(pq.size() > 1){
            int top1 = pq.top();
            pq.pop();
            
            int top2 = pq.top();
            pq.pop();
            
            count++;
            top1--;
            top2--;
            
            if(top1 > 0){
                pq.push(top1);
            }
            if(top2 > 0){
                pq.push(top2);
            }
        }
        return count;
    }
};