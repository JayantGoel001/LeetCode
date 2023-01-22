class Solution {
public:
    bool isAllDigits(string &str){
        for(auto it : str){
            if(it < '0' || it > '9'){
                return false;
            }
        }
        return true;
    }
    int maximumValue(vector<string>& strs) {
        int maxi = INT_MIN;
        
        for(auto str : strs){
            if(isAllDigits(str)){
                maxi = max(maxi, stoi(str));
            }else{
                maxi = max(maxi, (int)str.size());
            }
        }
        return maxi;
    }
};