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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || p==nullptr || q==nullptr){
            return root;
        }
        TreeNode* curr = root;
        while(curr!=nullptr){
            if(min(p->val,q->val)>curr->val){
                curr=curr->right;
            }
            else if(max(p->val,q->val)<curr->val){
                curr=curr->left;
            }
            else{
                return curr;
            }
        }
        return nullptr;
    }
};
