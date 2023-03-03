class Solution {
public:
    int strStr(string haystack, string needle) {
        
        for(int i=0;i<haystack.size();i++){
            int k = i;
            int j = 0;
            while(k < haystack.size() && j < needle.size() && haystack[k] == needle[j]){
                k++;
                j++;
            }
            if(j == needle.size()){
                return i;
            }
        }
        return -1;
    }
};