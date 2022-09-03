class Solution {
public:
	//To find digits in the current number
    int digits(int x) {
        int count = 0;
        while(x){
			count++;
            x = x/10;
        }
        return count;
    }
    void findNumbers(int cur_digit , int n ,int k, vector<int> &result){
		//Base case
        if(digits(cur_digit ) == n) {
            result.push_back(cur_digit);
            return;
        }
        for(int i=0;i<10;i++) {
           int last_digit = cur_digit  % 10;
           if(abs(last_digit - i) == k) 
           {
               findNumbers((cur_digit *10 + i), n, k, result); 
           } 
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> result; 
        for(int i=1;i<10;i++) {
            findNumbers(i, N, K, result);    
        }
        return result; 
    }
};