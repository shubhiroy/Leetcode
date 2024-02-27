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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> zigzag;
        if (root == NULL)
            return zigzag;
        deque<TreeNode *> dq;
        dq.push_back(root);
        dq.push_back(NULL);
        TreeNode *node = root;
        int reverse = 1;
        vector<int> lvl;
        while (!dq.empty())
        {
            TreeNode *temp;
            // cout<<reverse;
            if (reverse == 1)
            {
                temp = dq.front();
                dq.pop_front();
            }
            else
            {
                temp = dq.back();
                dq.pop_back();
            }
            if (temp == NULL)
            {
                reverse = reverse * -1;
                if (!dq.empty())
                {
                    if (reverse == 1)
                        dq.push_back(NULL);
                    else
                        dq.push_front(NULL);
                }
                zigzag.push_back(lvl);
                lvl = {};
            }
            else
            {
                lvl.push_back(temp->val);
                if (reverse == 1)
                {
                    if (temp->left != NULL)
                        dq.push_back(temp->left);
                    if (temp->right != NULL)
                        dq.push_back(temp->right);
                }
                else
                {
                    if (temp->right != NULL)
                        dq.push_front(temp->right);
                    if (temp->left != NULL)
                        dq.push_front(temp->left);
                }
            }
        }
        return zigzag;
    }
};