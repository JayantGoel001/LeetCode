class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        
        vector<string> v;
        for(auto it : nums){
            if(it == INT_MIN || s.find(it - 1) == s.end()){
                int num = it;
                
                while(num != INT_MAX && s.find(num + 1) != s.end()){
                    num++;
                }
                string str = "";
                if(it == num){
                    str += to_string(it);
                }else{
                    str += to_string(it) + "->" + to_string(num);
                }
                v.push_back(str);
            }
            
        }
        return v;
    }
};