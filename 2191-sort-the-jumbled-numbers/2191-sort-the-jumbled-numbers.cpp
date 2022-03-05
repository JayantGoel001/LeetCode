class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapp, vector<int>& nums) {
        
        auto comp = [&](int num1,int num2)-> bool {
            int _num1 = 0;
            int _num2 = 0;
            
            if(num1 == 0){
                _num1 = mapp[num1];
            }
            if(num2 == 0){
                _num2 = mapp[num2];
            }
            int x = 1;
            while(num1){
                _num1 = _num1 + mapp[num1%10] * x;
                x *= 10;
                num1/=10;
            }
            x = 1;
            while(num2){
                _num2 = _num2 + mapp[num2%10] * x;
                x *= 10;
                num2/=10;
            }
            return _num1 < _num2;
        };

        sort(nums.begin(),nums.end(),comp);
        return nums;
    }
};