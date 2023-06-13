//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int,vector<int>,greater<int>> pq;
	    
	    for(int i=0;i<n;i++){
	        pq.push(arr[i]);
	        
	        if(pq.size() > k){
	            pq.pop();
	        }
	    }
	    vector<int> v(pq.size(), 0);
	    int i = pq.size();
	    while(!pq.empty()){
	        v[--i] = pq.top();
	        pq.pop();
	    }
	    return v;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends