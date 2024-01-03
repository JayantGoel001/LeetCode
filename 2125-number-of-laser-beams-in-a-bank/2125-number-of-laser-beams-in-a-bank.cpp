class Solution {
public:
    int countOne(string &str){
        int c = 0;
        for(auto it : str){
            c += (it == '1');
        }
        return c;
    }
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        for(auto it : bank){
            int x = countOne(it);
            if(x!=0){
                v.push_back(x);
            }
        }
        int prod = 0;
        for(int i=1;i<v.size();i++){
            prod += v[i] * v[i - 1];
        }
        return prod;
    }
};