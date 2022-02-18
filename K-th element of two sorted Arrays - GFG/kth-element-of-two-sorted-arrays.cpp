// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k){
        
        if(m == 0){
            return arr1[k-1];
        }
        if(n == 0){
            return arr2[k-1];
        }
        if(k == 1){
            return min(arr1[0],arr2[0]);
        }
        int i = min(n,k/2);
        int j = min(m,k/2);
        
        if(arr1[i-1] < arr2[j-1]){
            return kthElement(arr1+i,arr2,n-i,m,k-i);
        }else{
            return kthElement(arr1,arr2+j,n,m-j,k-j);
        }
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends