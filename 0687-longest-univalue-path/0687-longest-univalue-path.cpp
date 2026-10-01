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
    int maxi(TreeNode* root,int &len){
        int lf=root->left?maxi(root->left,len):0;
        int rg=root->right?maxi(root->right,len):0;
        int resl=root->left&&root->val==root->left->val?lf+1:0;
        int resr=root->right&&root->val==root->right->val?rg+1:0;
        len=max(len,resl+resr);
        return max(resl,resr);
    }
    int longestUnivaluePath(TreeNode* root) {
        int len=0;
        if(root){
            maxi(root,len);
        }
        return len;
    }
};