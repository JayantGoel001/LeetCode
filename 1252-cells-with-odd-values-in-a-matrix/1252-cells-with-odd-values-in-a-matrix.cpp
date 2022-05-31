class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> M(m,false),N(n,false);
        for(auto it : indices){
            M[it[0]] ^= true;
            N[it[1]] ^= true;
        }
        
        int r = 0;
        int c = 0;
        for(int i=0;i<m;i++){
            if(M[i]){
                r++;
            }
        }
        for(int j=0;j<n;j++){
            if(N[j]){
                c++;
            }
        }
        return r * n + m * c - 2 * r * c;
    }
};