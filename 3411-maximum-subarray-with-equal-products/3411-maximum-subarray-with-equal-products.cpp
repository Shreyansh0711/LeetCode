class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = min(n, 2);

        for(int i = 0; i < n; i++) {
            __int128 p = 1;
            long long g = 0, l = 1;

            for(int j = i; j < n; j++) {
                long long x = nums[j];

                if(gcd(l, x) != 1) break;
                if(l > LLONG_MAX / x) break;

                l *= x;
                g = gcd(g, x);
                p *= x;

                if(p == (__int128)g * l)
                    ans = max(ans, j-i+1);
            }
        }

        return ans;
    }
};