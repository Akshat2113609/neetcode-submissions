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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return DFS(root,0,targetSum);
    }
    bool DFS(TreeNode* node , int currSum , int targetSum){
        if(node==nullptr){
            return false;
        }
        currSum+=node->val;
        if(node->left==nullptr && node->right==nullptr){
            return (currSum==targetSum);
        }
        return DFS(node->left,currSum,targetSum) || DFS(node->right,currSum,targetSum);
    }
};