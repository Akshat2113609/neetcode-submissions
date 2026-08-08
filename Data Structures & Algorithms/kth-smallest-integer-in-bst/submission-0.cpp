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
    void Inorder(TreeNode* root, vector<int>&inorder){
        if(root==nullptr){
            return ;
        }
        Inorder(root->left,inorder);
        inorder.push_back(root->val);
        Inorder(root->right,inorder);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr){
            return 0;
        }
        vector<int>inorder;
        Inorder(root,inorder);
        int n = inorder.size();
        if(k>n){
            k=k%n;
        }
        return inorder[k-1];
    }
};
