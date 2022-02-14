// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> v;
    vector<vector<bool>> vis;
    bool isSafe(vector<vector<int>> &m,int n,int x,int y){
        return x>=0 && y>=0 && x < n && y < n && m[x][y] == 1 && !vis[x][y];
    }
    void generatePath(vector<vector<int>> &m,int n,string str="",int x=0,int y=0){
        if(x < 0 || y < 0){
            return;
        }
        if(n-1 == x && n-1 == y){
            if(str!=""){
                v.push_back(str);
            }
        }else if(x < n || y < n){
            vis[x][y] = true;
            if(isSafe(m,n,x+1,y)){
                generatePath(m,n,str+"D",x+1,y);
            }
            if(isSafe(m,n,x,y+1)){
                generatePath(m,n,str+"R",x,y+1);
            }
            if(isSafe(m,n,x-1,y)){
                generatePath(m,n,str+"U",x-1,y);
            }
            if(isSafe(m,n,x,y-1)){
                generatePath(m,n,str+"L",x,y-1);
            }
            vis[x][y] = false;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] == 1){ 
            for(int i=0;i<n;i++){
                vis.push_back(vector<bool>());
                for(int j=0;j<n;j++){
                    vis[i].push_back(false);
                }
            }
            generatePath(m,n);
        }
        return v;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends