class Solution {
public:
    pair<int,int> dfs(TreeNode* root){
        if(!root) return {0,0};

        auto l=dfs(root->left);
        auto r=dfs(root->right);

        int notTake=max(l.first,l.second)+max(r.first,r.second);
        int take=root->val+l.first+r.first;

        return {notTake,take};
    }

    int rob(TreeNode* root) {
        auto ans=dfs(root);
        return max(ans.first,ans.second);
    }
};