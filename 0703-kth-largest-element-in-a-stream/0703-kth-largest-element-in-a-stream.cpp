class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        for(auto it : nums){
            pq.push(it);
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        this->k = k;
        
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size() > k){
            pq.pop();
        }
        
        return pq.top();
    }
};