class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        int n=1<<nums.size();
        for(int i=0;i<n;i++){
            vector<int>curr;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j))curr.push_back(nums[j]);
            }
            v.push_back(curr);
        }
        return v;
    }
};