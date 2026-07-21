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
    int Diameter(TreeNode*root){
        if(root==nullptr){
            return 0;
        }
        return 1+max(Diameter(root->left),Diameter(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
       if(root==nullptr){
            return 0;
        }
        int left = Diameter(root->left);
        int right = Diameter(root->right);
        int diameter = left+right;
        int ans = max(diameter,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
        return ans;
    }
};
