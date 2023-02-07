#define pii pair<int,int>
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxi = 0;
        
        pii bsk1 = {-1, 0};
        pii bsk2 = {-1, 0};
        
        for(int i=0;i<fruits.size();i++){
            if(bsk1.first == -1 || fruits[bsk1.first] == fruits[i]){
                bsk1.first = i;
                bsk1.second++;
            }else if(bsk2.first == -1 || fruits[bsk2.first] == fruits[i]){
                bsk2.first = i;
                bsk2.second++;
            }else{
                int prev = fruits[i - 1];
                bsk1 = {i - 1, abs(bsk1.first - bsk2.first)};
                bsk2 = {i, 1};
            }
            
            maxi = max(maxi, bsk1.second + bsk2.second);
        }
        return maxi;
    }
};