class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int start = 0;
        int i = 0;
        for(auto it : pushed){
            pushed[i] = it;
            
            while(i < pushed.size() && start < popped.size() && pushed[i] == popped[start]){
                i--;
                start++;
            }
            i++;
        }
        
        return start == popped.size();
    }
};