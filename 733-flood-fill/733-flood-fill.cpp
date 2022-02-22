#define pii pair<int,int>
class Solution {
public:
    bool isSafe(int i,int j,int n,int m,vector<vector<int>>& image,int prev){
        return i >= 0 && i < n && j >= 0 && j < m && image[i][j] == prev;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pii> q;
        q.push({sr,sc});
        
        int prev = image[sr][sc];
        
        int n = image.size();
        int m = image[0].size();
        
        while(!q.empty()){
            pii top = q.front();
            q.pop();
            
            if(image[top.first][top.second] != newColor){
                image[top.first][top.second] = newColor;

                if(isSafe(top.first-1,top.second,n,m,image,prev)){
                    q.push({top.first-1,top.second});
                }
                if(isSafe(top.first+1,top.second,n,m,image,prev)){
                    q.push({top.first+1,top.second});
                }
                if(isSafe(top.first,top.second-1,n,m,image,prev)){
                    q.push({top.first,top.second-1});
                }
                if(isSafe(top.first,top.second+1,n,m,image,prev)){
                    q.push({top.first,top.second+1});
                }
            }
        }
        return image;
    }
};