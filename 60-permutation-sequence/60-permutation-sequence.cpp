class Solution {
public:
    char its(int n){
        return n + 48;
    }
    
    string getPermutation(int n, int k) {
        string res = "";
        
        vector<int> fact(n + 1,1);
        vector<int> v(n,1);
        for(int i=2;i<=n;i++){
            fact[i] = fact[i-1] * i;
            v[i-1] = i;
        }
        k--;
        
        while(n!=0){
            int x = k/fact[n-1];
            res += its(v[x]);
            v.erase(v.begin() + x);
            k = k%fact[n-1];
            n--;
        }    
        return res;
    }
};