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
    // void Dfs(TreeNode* &curr,TreeNode* root1, TreeNode* root2){
    //     if(root1==nullptr && root2==nullptr){
    //         curr = nullptr;
    //         return ;
    //     }
    //     curr = new TreeNode();
    //     if(root1==nullptr && root2!=nullptr){
    //         curr->val = root2->val;
    //         Dfs(curr->left, nullptr, root2->left);
    //         Dfs(curr->right, nullptr, root2->right);
    //     }
    //     else if(root1!=nullptr && root2==nullptr){
    //         curr->val = root1->val;
    //         Dfs(curr->left, root1->left, nullptr);
    //         Dfs(curr->right, root1->right, nullptr);
    //     }
    //     else{
    //         curr->val = root1->val + root2->val;
    //         Dfs(curr->left,root1->left,root2->left);
    //         Dfs(curr->right,root1->right,root2->right);
    //     }
    // }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr){
            return root2;
        }
        if(root2==nullptr){
            return root1;
        }
        root1->val+=root2->val;
        root1->left = mergeTrees(root1->left,root2->left);
        root1->right = mergeTrees(root1->right,root2->right);
        return root1;
    }
};