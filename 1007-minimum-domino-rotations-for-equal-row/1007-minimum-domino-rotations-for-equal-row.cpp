class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int mini = n+1;
        for(int j=1;j<=6;j++){
            int count1 = 0;
            int count2 = 0;
            int cs = 0;
            bool flag = true;
            for(int i=0;i<n;i++){
                if(tops[i] == j && bottoms[i] == j){
                    cs++;
                }else if(bottoms[i] == j){
                    count1++;
                }else if(tops[i] == j){
                    count2++;
                }else{
                    flag = false;
                    break;
                }
            }
            if(flag && count1 + count2 + cs == n){
                mini = min({mini, count1, count2});
            }
        }
        return mini == n + 1 ? -1 : mini;
    }
};