class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;
        
        for(auto sent : sentences){
            int count = 1;
            int i = 0;
            while(i < sent.size()){
                if(sent[i] == ' '){
                    count++;
                }
                i++;
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }
};