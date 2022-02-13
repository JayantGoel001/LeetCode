// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    static bool cmp(pair<int,int> p1,pair<int,int> p2){
        return p1.second < p2.second;
    }
    int maxMeetings(int start[], int end[], int n){
        pair<int,int> arr[n];
        for(int i=0;i<n;i++){
            arr[i] = {start[i],end[i]};
        }
        
        sort(arr,arr+n,cmp);
        
        int count = 1;
        pair<int,int> initial = arr[0];
        
        for(int i=1;i<n;i++){
            if(arr[i].first > initial.second){
                count++;
                initial = arr[i];
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends