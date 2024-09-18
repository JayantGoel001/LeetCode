class Solution {
public:
    static bool cmp(string str1,string str2){
        string temp = str1;
        str1.append(str2);
        str2.append(str1);
        
        return str1 > str2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        
        for(auto it : nums){
            v.push_back(to_string(it));
        }
        sort(v.begin(),v.end(),cmp);
        
        string str = "";
        for(auto it : v){
            str.append(it);
        }
        if(str[0] == '0'){
            return "0";
        }
        return str;
    }
};