class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> st;
        st.insert(2);
        st.insert(3);
        st.insert(5);
        st.insert(7);
        st.insert(11);
        st.insert(13);
        st.insert(17);
        st.insert(19);
        
        int count = 0;
        for(int i=left;i<=right;i++){
            int num = i;
            
            int bits = 0;
            while(num){
                bits += num & 1;
                num >>= 1;
            }
            count += st.find(bits) != st.end();
        }
        return count;
    }
};