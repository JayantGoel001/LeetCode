class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){
            return 0;
        }
        int start = 0;
        int end = needle.size()-1;
        
        int hay = 0;
        int nee = 0;
        for(int i=0;i<needle.size();i++){
            hay += (haystack[i] - 'a' + 1);
            nee += (needle[i] - 'a' + 1);
        }
        while(end < haystack.size()){
            if(hay == nee){
                string str = haystack.substr(start,needle.size());
                if(str == needle){
                    return start;
                }
            }
            hay -= (haystack[start] - 'a' + 1);
            start++;
            end++;
            hay += (haystack[end] - 'a'  + 1);
        }
        return -1;
    }
};