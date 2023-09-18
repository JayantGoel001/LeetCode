//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to check if given number n is a power of two.
    long long power(long long x,int y){
        if(y == 0){
            return (long long)1;
        }else{
            if(y % 2 == 0){
                return power(x * x, y / 2);
            }else{
                return x * power(x * x, y / 2);
            }
        }
    }
    bool isPowerofTwo(long long n){
        return n!=0 && power((long long)2, log(n)/log(2)) == n;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}

// } Driver Code Ends