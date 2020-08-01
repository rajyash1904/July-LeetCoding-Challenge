/*

Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

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
    int search(vector<int>& in,int l,int r,int k)
    {
        int i;
        for(i=l;i<=r;i++)
        {
            if(in[i]==k) break;
        }
        return i;
    }
    
    TreeNode* help(vector<int>& in,vector<int>& po,int l,int r,int* pind)
    {
        if(l>r) return NULL;
        
        TreeNode* root= new TreeNode(po[*pind]);
        (*pind)--;
        
        if(l==r) return root;
        
        int ind =search(in,l,r,root->val);
        
        root->right= help(in,po,ind+1,r,pind);
        root->left = help(in,po,l,ind-1,pind);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n=inorder.size();
        int pind= n-1;
        return help( inorder, postorder, 0, n-1, &pind);
    }
};