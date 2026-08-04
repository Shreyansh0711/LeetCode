class Solution {
public:
   int find(int idx, int target, vector<int>& arr, vector<vector<int>> &dp) {
		if (idx == 0) {
			if (target == 0 && arr[0] == 0)
				return 2;
			if (target == 0 || arr[0] == target)
				return 1;
			return 0;
		}
		if (dp[idx][target] != -1) {
			return dp[idx][target];
		}
		int np = find(idx - 1, target, arr, dp);
		int pick = 0;
		if (arr[idx] <= target) {
			pick = find(idx - 1, target - arr[idx], arr, dp);
		}
		
		return dp[idx][target] = (pick + np);
	}
    int findTargetSumWays(vector<int>& nums, int target) {
        int tot = 0;
		for (int x:nums) {
			tot += x;
		}
		if ((tot - target)%2 != 0 || (tot - target)<0) {
			return 0;
		}
		vector<vector<int>> dp(nums.size(), vector<int>((tot - target)/2 + 1, -1));
		return find(nums.size() - 1, (tot - target)/2, nums, dp);
    }
};