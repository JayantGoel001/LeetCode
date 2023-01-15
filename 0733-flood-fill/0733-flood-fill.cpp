#define pii pair<int,int>
class Solution {
public:
    bool isSafe(vector<vector<int>>& image, int x, int y, int n, int m, int c){
        return x>=0 && x < n && y >= 0 && y < m && image[x][y] == c;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pii> q;
        q.push({sr, sc});
        int c = image[sr][sc];
        
        while(!q.empty()){
            pii top = q.front();
            q.pop();
            
            if(image[top.first][top.second] != color){
                image[top.first][top.second] = color;
                
                if(isSafe(image, top.first - 1, top.second, image.size(), image[0].size(), c)){
                    q.push({top.first - 1, top.second});
                }
                if(isSafe(image, top.first + 1, top.second, image.size(), image[0].size(), c)){
                    q.push({top.first + 1, top.second});
                }
                if(isSafe(image, top.first, top.second - 1, image.size(), image[0].size(), c)){
                    q.push({top.first, top.second - 1});
                }
                if(isSafe(image, top.first, top.second + 1, image.size(), image[0].size(), c)){
                    q.push({top.first, top.second + 1});
                }
            }
        }
        return image;
    }
};