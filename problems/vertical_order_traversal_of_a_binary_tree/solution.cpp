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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL) return v;
       map<int,map<int,multiset<int>>> m;
       queue<pair<TreeNode*, pair<int,int>>> q;
       lvlTraverse(root,q,m);
        for(auto o: m){
            vector<int> col;
            for(auto i:o.second){
                col.insert(col.end(),i.second.begin(), i.second.end());
            }
            v.push_back(col);
        }
        return v;
    }

private:
    void lvlTraverse(TreeNode* node, queue<pair<TreeNode*, pair<int,int>>> &q, map<int,map<int,multiset<int>>> &m){
        q.push({node,{0,0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x=temp.second.first, y=temp.second.second;
            m[y][x].insert(temp.first->val);
            if(temp.first->left){
                q.push({temp.first->left,{x+1,y-1}});
            }
            if(temp.first->right){
                q.push({temp.first->right,{x+1,y+1}});
            }
        }
    }

};