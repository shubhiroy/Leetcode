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
// #include <vector>
// class Solution
// {
// public:
//     vector<int> preorderTraversal(TreeNode *root)
//     {
//         std::vector<int> preorder;
//         if (root == NULL)
//         {
//             return preorder;
//         }
//         stack<TreeNode *> s;
//         s.push(root);
//         while (!s.empty())
//         {
//             TreeNode *temp = s.top();
//             s.pop();
//             preorder.push_back(temp->val);
//             if (temp->right != NULL)
//             {
//                 s.push(temp->right);
//             }
//             if (temp->left != NULL)
//             {
//                 s.push(temp->left);
//             }
//         }
//         return preorder;
//     }
// };

#include <vector>
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        if (root == NULL)
        {
            return preorder;
        }
        preOrder(root, preorder);
        return preorder;
    }

    void preOrder(TreeNode *root, vector<int> &preorder)
    {
        if (root == NULL)
        {
            return;
        }

        preorder.push_back(root->val);
        preOrder(root->left, preorder);
        preOrder(root->right, preorder);
    }
};
