1class Solution {
2public:
3    int ans = 0;
4
5    struct Info {
6        bool isBST;
7        int mn, mx, sum;
8    };
9
10    Info dfs(TreeNode* root) {
11        if (!root)
12            return {true, INT_MAX, INT_MIN, 0};
13
14        Info left = dfs(root->left);
15        Info right = dfs(root->right);
16
17        if (left.isBST && right.isBST &&
18            root->val > left.mx &&
19            root->val < right.mn) {
20
21            int currSum = left.sum + right.sum + root->val;
22            ans = max(ans, currSum);
23
24            return {
25                true,
26                min(root->val, left.mn),
27                max(root->val, right.mx),
28                currSum
29            };
30        }
31
32        return {false, INT_MIN, INT_MAX, 0};
33    }
34
35    int maxSumBST(TreeNode* root) {
36        dfs(root);
37        return ans;
38    }
39};