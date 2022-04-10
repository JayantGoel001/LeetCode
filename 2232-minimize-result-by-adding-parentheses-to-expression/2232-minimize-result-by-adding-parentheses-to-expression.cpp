#define pii pair<int,int>
class Solution {
public:
    string getSubstring(string s,int low,int high){
        string str = "";
        for(int i=low;i<high;i++){
            str += s[i];
        }
        return str;
    }
    string minimizeResult(string exp) {
        int plus = -1;
        for(int i=0;i<exp.size();i++){
            if(exp[i] == '+'){
                plus = i;
            }
        }
        
        int minNumber = INT_MAX;
        string returnString = "";

        for (int left = 0; left < plus; left ++) {
            for (int right = plus + 2; right <= exp.size(); right++) {

                string leftMultiplier = exp.substr(0, left);
                int lM = 0;
                
                if (leftMultiplier.size() == 0) {
                    lM = 1;
                } else {
                    lM = stoi(leftMultiplier);
                }
                
                int leftAdd = stoi(getSubstring(exp, left, plus));
                
                int rightAdd = stoi(getSubstring(exp, plus + 1, right));
                
                string rightMultiplier = exp.substr(right);
               
                int rM = 0;
                if (rightMultiplier.size() == 0) {
                    rM = 1;
                } else {
                    rM = stoi(rightMultiplier);
                }

                int calculated = lM * (leftAdd + rightAdd) * rM;
                
                if (calculated < minNumber) {
                    minNumber = calculated; 
                    leftMultiplier = left == 0 ? "" : leftMultiplier;
                    rightMultiplier = right == exp.size() ? "" : rightMultiplier;
                    returnString = leftMultiplier + "(" + to_string(leftAdd) +  "+" + to_string(rightAdd) + ")" + rightMultiplier ;
                }
            }
        }
        return  returnString;   
    }
};