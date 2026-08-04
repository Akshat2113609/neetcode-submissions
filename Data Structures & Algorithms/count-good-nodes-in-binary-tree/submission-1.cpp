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
    int goodNodes(TreeNode* root) {
        return DFS(root,root->val);
    }
    int DFS(TreeNode* root, int maxVal){
        if(root==nullptr){
            return 0;
        }
        int res;
        if(root->val>=maxVal){
            res = 1;
        }
        else{
            res = 0;
        }
        maxVal = max(root->val,maxVal);
        res+=DFS(root->left,maxVal);
        res+= DFS(root->right,maxVal);
        return res;
    }
};
