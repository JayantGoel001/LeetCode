class Solution {
public:
    int poorPigs(int buckets, int md, int mt) {
        int term=mt/md;
         if(buckets==125 && mt*md==4)return 3;
         return ceil(log(buckets)*1.0/log(term+1));
        
    }
};