class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        
        int count = 0;
        for(int j=0;j<m;j++){
            int x = 0;
            for(int i=0;i<n;i++){
                if(strs[i][j] < x){
                    count++;
                    break;
                }
                x = strs[i][j];
            }
        }
        return count;
    }
};