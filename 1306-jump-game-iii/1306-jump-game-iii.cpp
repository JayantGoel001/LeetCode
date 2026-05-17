class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            if(arr[top] == 0){
                return true;
            }
            
            if(arr[top] != -1){
                int x = arr[top];
                arr[top] = -1;
                
                if(top - x >= 0 && arr[top - x] != -1){
                    q.push(top - x);
                }
                if(top + x < arr.size() && arr[top + x] != -1){
                    q.push(top + x);
                }
            }
        }
        
        return false;
    }
};