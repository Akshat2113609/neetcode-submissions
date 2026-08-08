class Solution {
public:
    void DFS(TreeNode* root, int &cnt, int &ans){
        if(root==nullptr || ans != -1){
            return ;
        }
        DFS(root->left,cnt,ans);
        if(ans != -1) return;
        cnt--;
        if(cnt==0){
            ans = root->val;
            return ;
        }
        DFS(root->right,cnt,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr){
            return 0;
        }
        int cnt = k;
        int ans = -1;
        DFS(root,cnt,ans);
        return ans;
    }
};