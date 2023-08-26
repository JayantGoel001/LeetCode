//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    
  public:
    bool isValid(int *ar,int k){
        int count = 0;
        for(int i=0;i<26;i++){
            if(ar[i] > 0){
                count++;
            }
        }
        return k>=count;
    }
    int longestKSubstr(string s, int k) {
        int ar[26];
        for(int i=0;i<26;++i){
            ar[i] = 0;
        }
        int uni = 0;
        for(auto it : s){
            if(ar[it-'a'] == 0){
                uni++;
            }
            ar[it - 'a']++;
        }
        if(uni < k){
            return -1;
        }
        for(int i=0;i<26;i++){
            ar[i] = 0;
        }
        int start = 0;
        int maxLen = 0;
        
        for(int i=0;i<s.size();i++){
            ar[s[i] - 'a']++;
            
            while(!isValid(ar,k)){
                ar[s[start]-'a']--;
                start++;
            }
            
            if(i - start + 1 > maxLen){
                maxLen = i - start + 1;
            }
        }
        return maxLen;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends