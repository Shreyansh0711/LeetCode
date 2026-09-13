class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        vector<int>a;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            while(!(a.size()==0)&&a.back()>nums[i]){
                a.pop_back();
            }
            ans+=lower_bound(a.begin(),a.end(),nums[i])-a.begin();
            a.push_back(nums[i]);
        }
        return ans;
    }
};