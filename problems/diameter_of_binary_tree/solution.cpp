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
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int maxDepth = 0;
        getDepth(root, maxDepth);
        return maxDepth;
    }

private:
    int getDepth(TreeNode *node, int &maxDepth)
    {
        if (node == NULL)
            return 0;
        int leftDepth = getDepth(node->left, maxDepth);
        int rightDepth = getDepth(node->right, maxDepth);
        maxDepth = max(maxDepth, (leftDepth + rightDepth));
        return max(leftDepth, rightDepth) + 1;
    }
};