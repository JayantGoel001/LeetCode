// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends

class Solution{
    public:
    
    static bool cmp(Job j1,Job j2){
        return j1.profit > j2.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n){ 
        sort(arr,arr + n,cmp);
        
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i].dead);
        }
        
        vector<int> slot(maxi + 1,-1);
        
        int profit = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j = arr[i].dead;j>0;j--){
                if(slot[j] == -1){
                    slot[j] = i;
                    profit += arr[i].profit;
                    count++;
                    break;
                }
            }
        }
        return {count,profit};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends