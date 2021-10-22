#define pic pair<int,char> 
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        
        for(auto it : s){
            mp[it]++;
        }
        
        priority_queue<pic> pq;
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        
        string str = "";
        
        while(!pq.empty()){
            pic top= pq.top();
            pq.pop();
            
            for(int i=0;i<top.first;i++){
                str += top.second;
            }
        }
        return str;
    }
};