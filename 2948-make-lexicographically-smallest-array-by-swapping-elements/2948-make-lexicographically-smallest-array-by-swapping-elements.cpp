class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());

        vector<int>ans(n);
        int st=0;
        while(st<n){
            int end=st;
            while(end<n-1&&arr[end+1].first-arr[end].first<=limit){
                end++;
            }
            vector<int>idx;

            for(int i=st;i<=end;i++){
                idx.push_back(arr[i].second);
            }

            sort(idx.begin(),idx.end());

            for(int i=0;i<idx.size();i++){
                ans[idx[i]]=arr[st+i].first;
            }
            st=end+1;
        }
        return ans;
    }
};