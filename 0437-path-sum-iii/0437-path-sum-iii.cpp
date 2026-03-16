/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define ll long long int
class Solution {
public:
    unordered_map<ll,int> mp;
    Solution() {
        mp[0] = 1;
    }
    int pathSum(TreeNode* root, int targetSum, ll sum = 0) {
        if (!root) return 0;

        sum += (ll)root->val;
        int count = mp[sum - targetSum];

        mp[sum]++;
        count += pathSum(root->left, targetSum, sum);
        count += pathSum(root->right, targetSum, sum);
        mp[sum]--;

        return count;
    }
};