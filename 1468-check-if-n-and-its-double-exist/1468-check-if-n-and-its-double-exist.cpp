class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i = 0;i<n;i++){
            int x = arr[i] * 2;
            int pos = lower_bound(arr.begin(),arr.end(),x) - arr.begin();

            if(pos<n && pos != i && arr[pos] == x){
                return true;
            }
        }
        return false;
    }
};