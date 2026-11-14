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
    vector<int>solve(TreeNode* root, int &d,int &cnt){
        if(root==NULL)return {0};
        if(root->left==NULL&&root->right==NULL)return {1};

        vector<int>lfd=solve(root->left,d,cnt);
        vector<int>rgd=solve(root->right,d,cnt);

        for(auto i:lfd){
            for(auto j:rgd){
                if(i!=0&&j!=0&&i+j<=d)cnt++;
            }
        }
        vector<int>curr;
        for(auto l:lfd){
            if(l!=0&&l+1<=d){
                curr.push_back(l+1);
            }
        }
        for(auto i:rgd){
            if(i!=0&&i+1<=d){
                curr.push_back(i+1);
            }
        }
        return curr;
    }
    int countPairs(TreeNode* root, int d) {
        int cnt=0;
        solve(root,d,cnt);
        return cnt;
    }
};