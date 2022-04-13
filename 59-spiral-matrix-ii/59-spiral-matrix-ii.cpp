class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i = 0;
        int j = 0;
        int k = n - 1;
        int l = n - 1;
        
        vector<vector<int>> v(n,vector<int>(n,0));
        int count = 0;
        int maxi = n * n;
        
        while(i<=k && j<=l){
            for(int x = j;x<=l;x++){
                count++;
                v[i][x] = count;
            }
            i++;
            if(count>=maxi){
                break;
            }
            for(int x = i;x<=k;x++){
                count++;
                v[x][l] = count;
            }
            l--;
            if(count>=maxi){
                break;
            }
            
            for(int x = l;x>=j;x--){
                count++;
                v[k][x] = count;
            }
            k--;
            if(count>=maxi){
                break;
            }
            for(int x = k;x>=i;x--){
                count++;
                v[x][j] = count;
            }
            j++;
            if(count>=maxi){
                break;
            }
        }
        return v;
    }
};