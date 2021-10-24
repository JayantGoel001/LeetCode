class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int ar[size+1];
        for(int i =0;i<=size;i++){
            ar[i]=0;
        }
        for(auto it : citations){
            ar[min(it,size)]++;
        }
        int i = size-1;
        while(i>=0){
            ar[i]+=ar[i+1];
            if(ar[i+1]>=i+1){
                return i+1;
            }
            i--;
        }
        return 0;
    }
//     int hIndex(vector<int>& citations) {
//         sort(citations.begin(),citations.end());
        
//         int size = citations.size();
//         for(int i=0;i<size;i++){
//             if(citations[i] >= size - i){
//                 return size-i;
//             }
//         }
//         return 0;
//     }
};