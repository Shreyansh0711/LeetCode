class Solution {
public:
    int find(int idx, int target, vector<int>& nums,
             vector<vector<int>>& dp, int offset) {
        if (target < -offset || target > offset)
            return 0;

        if (idx < 0)
            return target == 0;

        if (dp[idx][target + offset] != -1)
            return dp[idx][target + offset];

        int plus = find(idx - 1, target - nums[idx], nums, dp, offset);
        int minus = find(idx - 1, target + nums[idx], nums, dp, offset);

        return dp[idx][target + offset] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        for (int x : nums)
            sum += x;
        if (abs(target) > sum)
            return 0;

        int offset = sum;
        vector<vector<int>> dp(nums.size(),
                               vector<int>(2 * sum + 1, -1));

        return find(nums.size() - 1, target, nums, dp, offset);
    }
};