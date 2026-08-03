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
    void Bfs(TreeNode* root,vector<int>&ans){
        if(root==nullptr){
            return ;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* rightNode = nullptr;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                rightNode = curr;
            }
            if(rightNode){
                ans.push_back(rightNode->val);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<int>ans;
       // ans.push_back(root->val);
        Bfs(root,ans);
        return ans;
    }
};
