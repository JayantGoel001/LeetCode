// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(bool graph[101][101],int u,int c,int V,vector<int> &color){
    for(int i=0;i<V;i++){
        if(graph[u][i] == 1 && color[i] == c){
            return false;
        }
    }
    return true;
}

bool colorGraph(bool graph[101][101],int m,int V,vector<int> &color,int v = 0){
    if(v == V){
        return true;
    }else{
        for(int i=1;i<=m;i++){
            if(isSafe(graph,v,i,V,color)){
                color[v] = i;
                if(colorGraph(graph,m,V,color,v+1)){
                    return true;
                }
                color[v] = 0;
            }
        }
        return false;
    }
}

bool graphColoring(bool graph[101][101], int m, int V){
    vector<int> color(V,0);
    return colorGraph(graph,m,V,color);
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends