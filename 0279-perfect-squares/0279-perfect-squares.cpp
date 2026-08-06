class Solution {
public:
    int find(int idx, int tar, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (tar % nums[idx] == 0)
                return tar / nums[idx];
            else
                return INT_MAX;
        }
        if (dp[idx][tar] != -1)
            return dp[idx][tar];
        int ntake = find(idx - 1, tar, nums, dp);
        int take = INT_MAX;
        if (nums[idx] <= tar) {
            int res = find(idx, tar - nums[idx], nums, dp);
            if (res != INT_MAX)
                take = 1 + res;
        }
        return dp[idx][tar] = min(take, ntake);
    }
    int numSquares(int n) {
        vector<int> nums;
        for (int i = 1; i * i <= n; i++) {
            nums.push_back(i * i);
        }
        vector<vector<int>> dp(nums.size(), vector<int>(n + 1, -1));
        return find(nums.size() - 1, n, nums, dp);
    }
};