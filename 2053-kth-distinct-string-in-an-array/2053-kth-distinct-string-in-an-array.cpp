#define pis pair<int, string>
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]] != 0){
                mp[arr[i]] = -1;
            }else{
                mp[arr[i]] = i + 1;
            }
        }
        priority_queue<pis> pq;
        
        for(auto it : mp){
            if(it.second != -1){
                pq.push({it.second, it.first});
                
                if(pq.size() > k){
                    pq.pop();
                }
            }
        }
        return pq.size() < k ? "" : pq.top().second;
    }
};