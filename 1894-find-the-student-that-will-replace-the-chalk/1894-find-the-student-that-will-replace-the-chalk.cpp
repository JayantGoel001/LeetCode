class Solution {
    public:
    int chalkReplacer(vector<int>& chalk, int k) {

        long long int sum = 0;
        for(int i=0;i<chalk.size();i++)
            sum += chalk[i];

        k = k%sum;
        long long  int ans = 0;

        for(int i=0;i<chalk.size();i++){

            if(chalk[i]<=k)
                k = k - chalk[i];
            else{
               ans = i;
                break;
            }
        }

        return ans;  
    }
};