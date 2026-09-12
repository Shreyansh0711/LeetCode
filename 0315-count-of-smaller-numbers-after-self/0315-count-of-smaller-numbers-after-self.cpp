class Solution {
public:
    const int OFFSET = 10001;

    void update(vector<int>& bit, int i) {
        while(i < bit.size()) {
            bit[i]++;
            i += i & -i;
        }
    }

    int q(vector<int>& bit, int i) {
        int sm = 0;

        while(i > 0) {
            sm += bit[i];
            i -= i & -i;
        }

        return sm;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> bit(20003);
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; i--) {
            int pos = nums[i] + OFFSET;
            ans[i] = q(bit, pos - 1);
            update(bit, pos);
        }
        return ans;
    }
};