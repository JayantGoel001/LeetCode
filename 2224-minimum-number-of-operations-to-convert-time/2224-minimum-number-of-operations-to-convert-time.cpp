class Solution {
public:
    int convertTime(string current, string correct) {
        int h1 = stoi(current.substr(0,2));
        int h2 = stoi(correct.substr(0,2));
        int m1 = stoi(current.substr(3));
        int m2 = stoi(correct.substr(3));
        int _1 = h1 * 60 + m1;
        int _2 = h2 * 60 + m2;
        
        int diff = _2 - _1;
        
        int count = 0;
        int ar[4] = {60, 15, 5, 1};
        for(int i=0;i<4;i++){
            count += diff/ar[i];
            diff%=ar[i];
        }
        return count;
    }
};