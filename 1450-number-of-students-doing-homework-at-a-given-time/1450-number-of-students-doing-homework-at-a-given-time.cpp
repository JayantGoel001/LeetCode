class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int count = 0;
        int n = startTime.size();
        
        for(int i=0;i<n;i++){
            count += (startTime[i] <= queryTime && queryTime <= endTime[i]);
        }
        return count;
    }
};