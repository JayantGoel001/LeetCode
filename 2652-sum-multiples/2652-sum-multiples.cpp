class Solution {
public:
    void update(vector<int> &v, int x){
        for(int i=0;i<v.size();i+=x){
            v[i] = true;
        }
    }
    int sumOfMultiples(int n) {
        vector<int> v(n + 1, false);
        update(v, 3);
        update(v, 5);
        update(v, 7);
        
        int count = 0;
        for(int i=0;i<v.size();i++){
            count += v[i] ? i : 0;
        }
        return count;
    }
};