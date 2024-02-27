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
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int maxPathSum = root->val;
        return max(getSum(root, maxPathSum), maxPathSum);
    }

private:
    int getSum(TreeNode* node, int &maxSum){
        if(node == NULL) return 0;
        int leftSum = getSum(node->left, maxSum);
        leftSum = leftSum<0?0:leftSum;
        int rightSum = getSum(node->right, maxSum);
        rightSum = rightSum<0?0:rightSum;
        maxSum = max(maxSum, leftSum + rightSum + node->val);
        return max(leftSum, rightSum) + node->val;
    }
};