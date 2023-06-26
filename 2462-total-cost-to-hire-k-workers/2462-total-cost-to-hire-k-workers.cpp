class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        long long ans=0;
        int cnt = 0,i=0,j=costs.size()-1;
        while(cnt<k){
            while(pq1.size()<candidates && i<=j) pq1.push(costs[i++]);
            while(pq2.size()<candidates && j>=i) pq2.push(costs[j--]);
            int a=pq1.size()>0?pq1.top():INT_MAX;
            int b=pq2.size()>0?pq2.top():INT_MAX;
            // cout<<a<<" "<<b<<"\n";
            if(a<=b){
                ans+=a;
                pq1.pop();
            }else{
                ans+=b;
                pq2.pop();
            }
            cnt++;
        }
        return ans;
    }
};