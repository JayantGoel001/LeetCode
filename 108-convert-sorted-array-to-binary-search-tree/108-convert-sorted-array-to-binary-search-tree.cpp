class Solution {
public:
    TreeNode* createTree(vector<int> &nums,int i,int j){
        if(i<=j){
            int mid = (i + j)/2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = createTree(nums,i,mid - 1);
            root->right = createTree(nums,mid + 1,j);
            return root;
        }
        return nullptr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree(nums,0,nums.size()-1);
    }
};