// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> v;
    
    void generateSubSet(vector<int> &arr,int size,int N,int x = 0,pair<int,int> temp = {0,0}){
        if(size == temp.second){
            v.push_back(temp.first);
        }else{
            for(int i=x;i<N;i++){
                temp.first += arr[i];
                temp.second++;
                
                generateSubSet(arr,size,N,i+1,temp);
                
                temp.first -= arr[i];
                temp.second--;
            }
        }
        
    }
    
    vector<int> subsetSums(vector<int> arr, int N){
        for(int i=0;i<=N;i++){
            generateSubSet(arr,i,N);
        }
        sort(v.begin(),v.end());
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends