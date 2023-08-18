class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count = 0;
        for(auto hour : hours){
            count += hour >= target;
        }
        return count;
    }
};