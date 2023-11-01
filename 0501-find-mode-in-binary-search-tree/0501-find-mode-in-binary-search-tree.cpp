class Solution {
public:
    vector<int> ans;
    int maxStreak = 0;
    int currStreak = 0;
    int currNum = 0;

    void add(int num) {
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
    }
    
    vector<int> findMode(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* friendNode;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                friendNode = curr->left;
                while (friendNode->right != nullptr && friendNode->right != curr) {
                    friendNode = friendNode->right;
                }
                
                if (friendNode->right == nullptr) {
                    friendNode->right = curr;
                    curr = curr->left;
                } else {
                    friendNode->right = nullptr;
                    add(curr->val);
                    curr = curr->right;
                }
            } else {
                add(curr->val);
                curr = curr->right;
            }
        }
        
        return ans;
    }
};