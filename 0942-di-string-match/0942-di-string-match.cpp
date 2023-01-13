class Solution {
public:
    vector<int> diStringMatch(string s) {
        int i = 0;
        int d = s.size();
        vector<int> v;
        for(auto it : s){
            if(it == 'I'){
                v.push_back(i++);
            }else{
                v.push_back(d--);
            }
        }
        v.push_back(i);
        return v;
    }
};