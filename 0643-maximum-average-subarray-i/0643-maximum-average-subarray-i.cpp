class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0;
        double sm = 0;
        double ans = -1e18;

        int n = nums.size();

        for(int r = 0; r < n; r++) {

            sm += nums[r];

            while(r - l + 1 > k) {
                sm -= nums[l];
                l++;
            }

            if(r - l + 1 == k) {
                ans = max(ans, sm);
            }
        }

        return ans / k;
    }
};