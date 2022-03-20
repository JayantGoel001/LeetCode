class Solution {
public:
    int countCollisions(string dir) {
        int count = 0;
        int n = dir.size();
        bool flag = false;
        for(int i=0;i<n;i++){
            if(dir[i] != 'L'){
                flag = true;
            }else{
                count += flag;
            }
        }
        flag = false;
        for(int i=n-1;i>=0;i--){
            if(dir[i] != 'R'){
                flag = true;
            }else{
                count += flag;
            }
        }
        return count;
    }
};