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

// Using 2 stacks
// class Solution
// {
// public:
//     vector<int> postorderTraversal(TreeNode *root)
//     {
//         vector<int> postorder;
//         if (root == NULL)
//             return postorder;

//         stack<TreeNode *> s1, s2;
//         s1.push(root);
//         while (!s1.empty())
//         {
//             TreeNode *temp = s1.top();
//             s1.pop();
//             s2.push(temp);
//             if (temp->left != NULL)
//             {
//                 s1.push(temp->left);
//             }
//             if (temp->right != NULL)
//             {
//                 s1.push(temp->right);
//             }
//         }

//         while (!s2.empty())
//         {
//             postorder.push_back(s2.top()->val);
//             s2.pop();
//         }
//         return postorder;
//     }
// };

// Using 1 Stack
// class Solution
// {
// public:
//     vector<int> postorderTraversal(TreeNode *root)
//     {
//         vector<int> postorder;
//         if (root == NULL)
//             return postorder;

//         stack<TreeNode *> s;
//         TreeNode *node = root;
//         // s.push(node);
//         while (node != NULL)
//         {
//             if (node->right != NULL)
//             {
//                 s.push(node->right);
//             }
//             s.push(node);
//             node = node->left;
//         }
//         while (!s.empty())
//         {
//             TreeNode *temp = s.top();
//             s.pop();
//             if (temp->right != NULL && !s.empty() && temp->right == s.top())
//             {
//                 TreeNode *rightNode = s.top();
//                 s.pop();
//                 s.push(temp);
//                 while (rightNode != NULL)
//                 {
//                     if (rightNode->right != NULL)
//                     {
//                         s.push(rightNode->right);
//                     }
//                     s.push(rightNode);
//                     rightNode = rightNode->left;
//                 }
//             }
//             else
//             {
//                 postorder.push_back(temp->val);
//             }
//         }
//         return postorder;
//     }
// };

// Using recurssion
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;
        if (root == NULL)
            return postorder;
        postorderTraverse(root, postorder);
        return postorder;
    }

    void postorderTraverse(TreeNode *node, vector<int> &postorder)
    {
        if (node == NULL)
            return;

        postorderTraverse(node->left, postorder);
        postorderTraverse(node->right, postorder);
        postorder.push_back(node->val);
    }
};