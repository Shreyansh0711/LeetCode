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
    TreeNode* find(vector<int>& postorder, vector<int>& inorder,int &pre,int l,int r,unordered_map<int,int>&mp){
        if(l>r)return NULL;
        int val=postorder[pre--];
        TreeNode *root=new TreeNode(val);
        int pos=mp[val];
        root->right=find(postorder,inorder,pre,pos+1,r,mp);
        root->left=find(postorder,inorder,pre,l,pos-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int pre=postorder.size()-1;
        return find(postorder,inorder,pre,0,postorder.size()-1,mp);
    }
};