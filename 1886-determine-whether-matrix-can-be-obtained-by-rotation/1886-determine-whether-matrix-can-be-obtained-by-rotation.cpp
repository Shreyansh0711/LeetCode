class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>> mat) {
        int n = mat.size();
        vector<vector<int>> ans(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][n - 1 - i] = mat[i][j];
            }
        }

        return ans;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target)
            return true;

        for (int k = 0; k < 4; k++) {
            if (mat == target)
                return true;
            mat = rotate(mat);
        }
        return false;
    }
};