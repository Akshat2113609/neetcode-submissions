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
    int Dfs(TreeNode* root,int &ans){
        if(root==nullptr){
            return 0;
        }
        int leftH = Dfs(root->left,ans);
        int rightH = Dfs(root->right,ans);
        int diameter = leftH + rightH;
        ans=max(ans,diameter);
        return 1+max(leftH,rightH);
    }
      void RightD(TreeNode* root,int &cnt2){
        if(root==nullptr){
            return ;
        }
        cnt2++;
        RightD(root->right,cnt2);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int ans = INT_MIN;
        Dfs(root,ans);
        return (ans);
    }
};
