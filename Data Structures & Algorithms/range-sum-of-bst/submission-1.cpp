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
    void inorderTraversal(TreeNode* root,vector<int>&inorder){
        if(root==nullptr){
            return ;
        }
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right,inorder);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>inorder;
        inorderTraversal(root,inorder);
        int startidx=-1;
        int endidx=-1;
        for(int i=0;i<inorder.size();i++){
            if(low<=inorder[i]){
                startidx=i;
                break;
            }
        }
        for(int i=inorder.size()-1;i>=0;i--){
            if(high>=inorder[i]){
                endidx=i;
                break;
            }
        }
        if(startidx==-1 || endidx==-1){
            return 0;
        }
        int sum=0;
        for(int i=startidx;i<=endidx;i++){
            sum+=inorder[i];
        }
        return sum;
    }
};