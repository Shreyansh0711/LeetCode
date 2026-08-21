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
    TreeNode* find(vector<int>& preorder, vector<int>& inorder,int&pre,int l,int r,unordered_map<int,int>& mp){
        if(l>r)return NULL;
        int val=preorder[pre++];
        TreeNode *root=new TreeNode(val);
        int pos=mp[val];
        root->left=find(preorder,inorder,pre,l,pos-1,mp);
        root->right=find(preorder,inorder,pre,pos+1,r,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int pre=0;
        int l=0;
        int r=inorder.size()-1;
        return find(preorder,inorder,pre,l,r,mp);
    }
};