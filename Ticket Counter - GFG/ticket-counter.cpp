//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int n, int k) {
        // code here
        int i=0;
        int j=n+1;
        int p=0;
        while((j-i)>k){
               
                i+=k;
                p++;
            if(j-i>k){
                j-=k;
                p--;
            }
            
        }
        int n1=0;
        if(j-i==1){
            if(p==1){
                return i;
            }
            return j;
        }
        if(j-i>1){
        n1 = j-i-1;
        }
        if(p==0){
            i+=n1;
            return i;
        }
        j-=n1;
        return j;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends