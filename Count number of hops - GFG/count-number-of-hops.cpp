//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int MOD = 1e9 + 7;
    long long countWays(int n){
        if(n <= 2){
            return n;
        }
        if(n == 3){
            return 4;
        }
        int res = 0;
        
        int x = 1;
        int y = 2;
        int z = 4;
        
        for(int i = 4;i <= n;i++){
            res = ((x + y) % MOD + z) % MOD;
            
            x = y;
            y = z;
            z = res;
        }
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends