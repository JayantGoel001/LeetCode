class Job{
    public:
    int start;
    int end;
    int profit;
    
    Job(int start,int end,int profit){
        this->start = start;
        this->end = end;
        this->profit = profit;
    }
};
class Solution {
public:
    int *dp;
    static bool cmp(Job *j1,Job *j2){
        return j1->start < j2->start;
    }
    int calculateProfit(vector<Job*> &job,int i,int n){
        if(i == n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        Job *j = job[i];
        Job *nextJob = new Job(j->end,INT_MIN,INT_MIN);
        
        int pos = lower_bound(job.begin(),job.end(),nextJob,cmp) - job.begin();
        
        dp[i] =  max(calculateProfit(job,i+1,n), j->profit + calculateProfit(job,pos,n));
        return dp[i];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        vector<Job*> job(n);
        for(int i=0;i<n;i++){
            job[i] = new Job(startTime[i],endTime[i],profit[i]);
        }
        sort(job.begin(),job.end(),cmp);
        
        dp = new int[n];
        for(int i=0;i<n;i++){
            dp[i] = -1;
        }
        
        return calculateProfit(job,0,n);
    }
};