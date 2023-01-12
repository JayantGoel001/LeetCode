class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> v(26, 0);
        for(auto it : word){
            v[it - 'a']++;
        }
        for(int i = 0;i<26;i++){
            if(v[i]){
                v[i] -= 1;
                int x = -1;
                
                bool flag = true;
                for(auto it : v){
                    if(it != 0){
                        if(x == -1){
                            x = it;
                        }else if(x != it){
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag){
                    return true;
                }
                v[i] += 1;
            }
            
        }
        
        return false;
    }
};