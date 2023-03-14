class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int count = 0;
        int num = 1;
        for(auto it : s){
            if(count + widths[it - 'a'] <= 100){
                count += widths[it - 'a'];
            }else{
                count = widths[it - 'a'];
                num++;
            }
        }
        
        return {num, count};
    }
};