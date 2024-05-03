class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        int sum1 = 0;
        int sum2 = 0 ;
        int n1 = version1.size();
        int n2 = version2.size();
        while(i < n1 || j < n2){
            while(i < n1 && version1[i] !='.'){
                sum1 = sum1 * 10 + (version1[i++] - '0');
            }
            while(j < n2 && version2[j] !='.'){
                sum2 = sum2 * 10 + (version2[j++] - '0');
            }
            if(sum1 > sum2){
                return 1;
            }
            if(sum1 < sum2){
                return -1;
            }
            i++;
            j++;
            sum1 = 0;
            sum2 = 0;
        }
        return 0;
    }
};