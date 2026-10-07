/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<vector<int>> adj = vector<vector<int>>(1001);

    void dfs(TreeNode* root){
        if(!root) return;

        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
            

        dfs(root->left);
        dfs(root->right);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        adj.resize(1001);
        dfs(root);
        queue<int>q;
        vector<int>vis(1001,false);
        q.push(target->val);
        vis[target->val]=true;
        while(k--){
            int sz=q.size();
            while(sz--){
                int node=q.front();
                q.pop();
                for(int next:adj[node]){
                    if(!vis[next]){
                        vis[next]=true;
                        q.push(next);
                    }
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};