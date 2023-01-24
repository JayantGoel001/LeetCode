#define pii pair<int,int>
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        vector<pii> v(n * n + 1);
        
        bool forward = true;
        int pos = 1;
        for(int i = n - 1;i >= 0; i--){
            for(int j = 0; j < n;j++){
                int _j = forward ? j : n - j - 1;
                v[pos++] = {i, _j};
            }
            forward = !forward;
        }
        
        vector<int> dist(n * n + 1, -1);
        dist[1] = 0;
        
        queue<int> q;
        q.push(1);
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            for(int i = top + 1;i <= min(top + 6, n * n); i++){
                int des = board[v[i].first][v[i].second] == -1 ? i : board[v[i].first][v[i].second];
                
                if(dist[des] == -1){
                    dist[des] = dist[top] + 1;
                    
                    q.push(des);
                }
            }
        }
        return dist[n * n];
    }
};