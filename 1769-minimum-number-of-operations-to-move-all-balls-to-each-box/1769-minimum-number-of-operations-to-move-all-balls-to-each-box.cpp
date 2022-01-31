class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> v;
        int size = boxes.size();
        for(int i=0;i<size;i++){
            int sum = 0;
            for(int j = 0;j<size;j++){
                sum += (i != j && boxes[j] == '1') * abs(i-j);
            }
            v.push_back(sum);
        }
        return v;
    }
};