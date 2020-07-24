/*

Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

*/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> sol;
        if(root==NULL) return sol;
        int order=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            vector<int> curr;
            while(len--)
            {
                TreeNode* temp= q.front();
                q.pop();
                curr.push_back(temp->val);
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(order%2==0)
                sol.push_back(curr);
            else
            {
                reverse(curr.begin(),curr.end());
                sol.push_back(curr);
            }
            order++;
        }
        return sol;
    }
};