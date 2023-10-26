class Solution {
public:
     int mod = pow(10,9) + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map <int, long> rootWithCount;
        rootWithCount[arr[0]] = 1;
        for(int i = 1; i < arr.size(); i++){
            long count = 1;
            for(auto j : rootWithCount){
                int rootEle = j.first;
                if(arr[i] % rootEle == 0 && rootWithCount.find(arr[i] / rootEle) != rootWithCount.end()){
                    count += rootWithCount[rootEle] * rootWithCount[arr[i] / rootEle];
                    
                }
            }
            rootWithCount[arr[i]] = count;
        }
        int noOfTrees = 0;
        for(auto i : rootWithCount){
            noOfTrees = (noOfTrees + i.second) % mod;
        }
        return noOfTrees;
    }
};