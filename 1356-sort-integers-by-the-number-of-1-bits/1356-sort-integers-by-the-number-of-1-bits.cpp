class Solution {
public:
    static bool cmp(int num1,int num2){
        int x1 = num1;
        int x2 = num2;
        
        int _num1 = 0;
        while(num1){
            _num1 += num1%2;
            num1 /= 2;
        }
        int _num2 = 0;
        while(num2){
            _num2 += num2%2;
            num2 /= 2;
        }
        return _num1 == _num2 ? x1 < x2 : _num1 < _num2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};