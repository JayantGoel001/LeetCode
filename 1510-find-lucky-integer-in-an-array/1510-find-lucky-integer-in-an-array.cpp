class Solution {
public:
    int findLucky(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            arr[i] = arr[i] * 501;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]/501 - 1 < arr.size()){
                arr[arr[i] / 501 - 1]++;
            }
        }
        int count = -1;
        for(int i=0;i<arr.size();i++){
            if(arr[i] % 501 == i + 1){
                count = max(count, i + 1);
            }
        }
        return count;
    }
};