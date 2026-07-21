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
    int Dfs(TreeNode* root){
      unordered_map<TreeNode*,pair<int,int>>mp;
      stack<TreeNode*>st;
      st.push(root);
      mp[root]={1,1};
      while(!st.empty()){
        TreeNode* curr = st.top();
        if(curr->left && mp.find(curr->left)==mp.end()){
           st.push(curr->left);
        }
        else if(curr->right && mp.find(curr->right)==mp.end()){
            st.push(curr->right);
        }
        else{
            st.pop();
            int leftHeight = mp[curr->left].first;
            int leftDiameter = mp[curr->left].second;
            int rightHeight = mp[curr->right].first;
            int rightDiameter = mp[curr->right].second;
            int height = 1 + max(leftHeight,rightHeight);
            int diameter = max(leftHeight+rightHeight,max(leftDiameter,rightDiameter));
            mp[curr]={height,diameter};
        }
      }
      return mp[root].second;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        return Dfs(root);
    }
};