// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n){
        for(int i=1;i<n;i++){
            A[i] += A[i-1];
        }
        unordered_map<int,int> mp;
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(mp[A[i]]!=0){
                maxi = max(maxi,i - mp[A[i]] + 1);
            }else{
                mp[A[i]] = i + 1;
            }
            if(A[i] == 0){
                maxi = max(maxi,i+1);
            }
        }
        return maxi;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends