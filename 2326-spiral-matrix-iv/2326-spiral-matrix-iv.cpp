class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ar(m,vector<int> (n,-1));
        int i = 0;
        int j = 0;
        int k = m-1;
        int l = n-1;
        
        while(head && i <= k && j <= l){
            int y = j;
            while(y <= l && head){
                ar[i][y++] = head->val;
                head = head->next;
            }
            i++;
            int x = i;
            while(x <= k && head){
                ar[x++][l] = head->val;
                head = head->next;
            }
            l--;
            y = l;
            while(j <= y && head){
                ar[k][y--] = head->val;
                head = head->next;
            }
            k--;
            x = k;
            while(i <= x && head){
                ar[x--][j] = head->val;
                head = head->next;
            }
            j++;
        }
        return ar;
    }
};