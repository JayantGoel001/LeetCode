class Solution {
public:
    vector<int> minOperations(string boxes) {
        int size = boxes.size();
        vector<int> v(size,0);
        int count = 0;
        int ops = 0;
        for(int i=0;i<size;i++){
            v[i] += ops;
            count += (boxes[i] == '1');
            ops += count;
        }
        ops = 0;
        count = 0;
        for(int i=size-1;i>=0;i--){
            v[i] += ops;
            count += (boxes[i] == '1');
            ops += count;
        }
        return v;
    }
};