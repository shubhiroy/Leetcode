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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> lvlorder;
        if (root == NULL)
            return lvlorder;

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> lvl;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                lvlorder.push_back(lvl);
                lvl = {};
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                lvl.push_back(temp->val);
                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }
        }
        return lvlorder;
    }
};