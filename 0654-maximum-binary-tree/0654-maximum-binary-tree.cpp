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
    int maxi(vector<int>& nums,int l,int r){
        int mxi=l;
        for(int i=l;i<r;i++){
            if(nums[mxi]<nums[i]){
                mxi=i;
            }
        }
        return mxi;
    }
     TreeNode* find(vector<int>& nums,int l,int r){
        if(l>=r)return NULL;
        int idx=maxi(nums,l,r);
        TreeNode*root=new TreeNode(nums[idx]);
        root->left=find(nums,l,idx);
        root->right=find(nums,idx+1,r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return find(nums,0,nums.size());
    }
};