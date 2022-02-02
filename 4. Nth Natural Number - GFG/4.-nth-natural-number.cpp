// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++


class Solution{
	public:
	long long int power(int x,int n){
	    if(n == 0){
	        return 1;
	    }else {
	        if(n%2==0){
	            return power(x*x,n/2);
	        }else{
	            return x * power(x*x,(n-1)/2);
	        }
	    }
	}
    long long findNth(long long N)
    {
        long long int res = 0;
        int i = 0;
        while(N!=0){
            res += (long long int)N%9 * power(10,i++);
            N /= 9;
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n , ans;
		cin>>n;
		Solution obj;
		ans = obj.findNth(n);
		cout<<ans<<endl;
	}
}

  // } Driver Code Ends