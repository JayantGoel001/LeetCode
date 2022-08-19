class Solution {
public:
    //app 1: using greedy approach in O(N) 
    
/* for each num in nums first try placing it in one of the existing subseq.
if no subseq. needs that number.
then, try creating a new subseq. of atleast length 3 starting with that num.

if neither of the two condtn is true, we return false
since, that num can't be a part of any subseq.

*/
    bool isPossible(vector<int>& nums) {
        //freq. map denotes no. of elements left to be placed in subseq.
        unordered_map<int,int> freq;
        for(int x: nums) freq[x]++;
        
        //hypothetical map which denotes the "next" number req. by subsequences.
        unordered_map<int,int> need;
        
        for(int n: nums){
            //all occurences of cur num is already taken
            if(freq[n] == 0) continue;
            
            if(need[n] > 0){ // "n" can be a part of some existing subseq.
                need[n]--;
                freq[n]--;
                
                need[n+1]++; //next req. num is now "N+1"
            }
            
            //try creating a new sub. of length atleast three
            else if(freq[n]>0 && freq[n+1]>0 && freq[n+2]>0){
                freq[n]--;
                freq[n+1]--;
                freq[n+2]--;
                
                //next num needed in subseq.
                need[n+3]++;
            }
            
            //above both condtn is false
            else{
                return false;
            }
        }
        
        return true;
    }
};