#define pii pair<int,int>
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pii> pq;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0;i<n;i++){
            int num = lower_bound(mat[i].begin(),mat[i].end(),0,greater<int>()) - mat[i].begin();
            pq.push({num,i});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> v;
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};