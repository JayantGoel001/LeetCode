class Solution {
public:
    bool validUtf8(vector<int>& arr) {
        int cnt = 0;
          for (auto it : arr)
          {
            if (cnt == 0)
            {
              if ((it >> 5) == 0b110) cnt=1;
              else if((it>>4)==0b1110) cnt=2;
              else if((it>>3)==0b11110) cnt=3;
              else if((it>>7)) return false;
            }else{
              if((it>>6)!=0b10) return false;
              cnt--;
            }
          }
          return cnt==0;
    }
};