class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        int start = 0;
        int count = 0;
        
        queue<int> q;
        q.push(start);
        
        vector<int> vis(arr.size(), false);
        vis[start] = true;
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                int top = q.front();
                q.pop();
                
                if(top == arr.size() - 1){
                    return count;
                }
                for(auto it : mp[arr[top]]){
                    if(!vis[it]){
                        vis[it] = true;
                        q.push(it);
                    }
                }
                if(top - 1 >= 0 && !vis[top - 1]){
                    vis[top - 1] = true;
                    q.push(top - 1);
                }
                if(top + 1 < arr.size() && !vis[top + 1]){
                    vis[top + 1] = true;
                    q.push(top + 1);
                }
                mp[arr[top]].clear();
            }
            count++;
        }
        return -1;
    }
};