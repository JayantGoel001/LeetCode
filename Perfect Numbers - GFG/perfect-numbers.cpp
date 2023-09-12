//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        if(N == 1ll){
            return 0;
        }
        long long sum = 1ll;
        for(long long i = 2;i * i <= N ;i++){
            if( N % i == 0 ){
                sum += i;
                if(N % (N / i) == 0){
                    sum += (N / i);
                }
            }
        }
        return sum == N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends