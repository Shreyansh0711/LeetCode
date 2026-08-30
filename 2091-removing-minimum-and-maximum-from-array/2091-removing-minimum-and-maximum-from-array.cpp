class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = min_element(nums.begin(), nums.end()) - nums.begin();
        int mx = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(mn, mx);
        int right = max(mn, mx);

        int front = right + 1;

        int back = n - left;

        int bothSides = (left + 1) + (n - right);

        return min({front, back, bothSides});
    }
};
