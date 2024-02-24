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
#include <vector>
// class Solution
// {
// public:
//     vector<int> inorderTraversal(TreeNode *root)
//     {
//         vector<int> inorder;
//         if (root == NULL)
//         {
//             return inorder;
//         }

//         stack<TreeNode *> s;
//         TreeNode *node = root;
//         while (node != NULL)
//         {
//             s.push(node);
//             node = node->left;
//         }

//         while (!s.empty())
//         {
//             TreeNode *temp = s.top();
//             s.pop();
//             inorder.push_back(temp->val);
//             if (temp->right != NULL)
//             {
//                 temp = temp->right;
//                 s.push(temp);
//                 temp = temp->left;
//                 while (temp != NULL)
//                 {
//                     s.push(temp);
//                     temp = temp->left;
//                 }
//             }
//         }

//         return inorder;
//     }
// };

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;
        if (root == NULL)
            return inorder;

        inorderTraverse(root, inorder);
        return inorder;
    }

    void inorderTraverse(TreeNode *node, vector<int> &inorder)
    {
        if (node == NULL)
        {
            return;
        }
        inorderTraverse(node->left, inorder);
        inorder.push_back(node->val);
        inorderTraverse(node->right, inorder);
    }
};
