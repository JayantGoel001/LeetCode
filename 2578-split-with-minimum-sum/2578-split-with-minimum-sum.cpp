class Solution {
public:
    int splitNum(int num) {
        vector<int> v;
        while(num){
            v.push_back(num % 10);
            num /= 10;
        }
        
        sort(v.begin(), v.end(), [&](const int p1, const int p2)->bool{
            return p1 < p2;
        });
        
        int num1 = 0;
        int num2 = 0;
        
        int i = 0;
        while(i < v.size()){
            if(i % 2){
                num2 = num2 * 10 + v[i++];
            }else{
                num1 = num1 * 10 + v[i++];
            }
        }
        return num1 + num2;
    }
};