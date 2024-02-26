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
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return checkBalance(root) != -1;
    }

private:
    int checkBalance(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        int leftDepth = checkBalance(node->left);
        if (leftDepth == -1)
            return leftDepth;
        int rightDepth = checkBalance(node->right);
        if (rightDepth == -1)
            return rightDepth;
        if (abs(leftDepth - rightDepth) > 1)
            return -1;
        return max(leftDepth, rightDepth) + 1;
    }
};