class Solution {
public:
    string getSmallestString(int n, int k) {
        string s="";
        for(int i=0;i<n;i++)
            s+='a';
        k=k-n;
        for(int i=n-1;i>=0;i--)
        {
            if(k==0)
                break;
            else if(k<25)
            {
                s[i] = (char)('a'+k); 
                k=0;
            }
            else{
                s[i] = (char)('a'+25);
                k = k - 25;
            }
        }
        return s;
    }
};