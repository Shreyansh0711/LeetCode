class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int sm = 0;
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        for (int it : nums) {
            sm=(sm+it)%k;
            if(sm<0){
                sm+=k;
            }
            count+=mp[sm];
            mp[sm]++;
        }
        return count;
    }
};