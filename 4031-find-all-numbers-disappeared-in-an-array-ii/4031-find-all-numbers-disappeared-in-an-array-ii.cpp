class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        //sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        unordered_map<int,int>mp;
        int j=lower;
        for(int x:nums)mp[x]++;
        while(j<=upper){
            if(mp.count(j)){
                j++;
                continue;
            }
            int st=j;
            while(j<=upper&&!mp.count(j)){
                j++;
            }
            ans.push_back({st,j-1});
        }
        return ans;
    }
};