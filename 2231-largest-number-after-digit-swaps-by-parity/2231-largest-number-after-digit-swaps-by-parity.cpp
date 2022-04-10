class Solution {
public:
    static bool cmp(int a1,int a2){
        return a1 > a2;
    }
    int largestInteger(int num) {
        vector<int> odd,even;
        int c = 0;
        int n = num;
        
        while(num){
            int c = num%10;
            if(c%2 != 0){
                odd.push_back(num%10);
            }else{
                even.push_back(num%10);
            }
            num/=10;
        }
        sort(odd.begin(),odd.end(),cmp);
        sort(even.begin(),even.end(),cmp);
        
        int res = 0;
        int i = 0;
        int j = 0;
        string str = to_string(n);
        for(int w=0;w<str.size();w++){
            int x = str[w] - '0';
            if(x % 2 == 0){
                res = res * 10 + even[j++];
            }else{
                res = res * 10 + odd[i++];
            }
        }
        return res;
    }
};