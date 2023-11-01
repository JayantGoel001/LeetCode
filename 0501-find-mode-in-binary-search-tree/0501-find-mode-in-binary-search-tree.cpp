class Solution {
public:
    vector<int> ans;
    int maxStreak = 0;
    int currStreak = 0;
    int currNum = 0;
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        dfs(node->left);
        
        int num = node->val;
        if (num == currNum) {
            currStreak++;
        } else {
            currStreak = 1;
            currNum = num;
        }

        if (currStreak > maxStreak) {
            ans = {};
            maxStreak = currStreak;
        }

        if (currStreak == maxStreak) {
            ans.push_back(num);
        }

        
        dfs(node->right);
    }
};