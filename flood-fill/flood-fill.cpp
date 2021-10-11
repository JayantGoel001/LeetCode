#define pii pair<int,int>
class Solution {
public:
    bool isSafe(int i,int j,int n,int m){
        return i>=0 && i < n && j>=0 && j < m;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pii> q;
        q.push({sr,sc});
        
        int oldColor = image[sr][sc];
        
        int X[] = {-1,0,1,0};
        int Y[] = {0,1,0,-1};
        
        int n = image.size();
        int m = image[0].size();
        
        while(!q.empty()){
            pii top = q.front();
            q.pop();
            
            if(image[top.first][top.second] == oldColor){
                image[top.first][top.second] = newColor;
                
                for(int i=0;i<4;i++){
                    if(isSafe(top.first+X[i],top.second+Y[i],n,m) && image[top.first+X[i]][top.second+Y[i]] != newColor){
                        q.push({top.first+X[i],top.second+Y[i]});
                    }
                }
            }
        }
        return image;
    }
};