class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        long long sum=0,mx=0;
        const int MOD=1e9+7;

        vector<int>a=nums1;
        sort(a.begin(),a.end());

        for(int i=0;i<n;i++){
            int prev=abs(nums1[i]-nums2[i]);
            sum+=prev;

            auto it=lower_bound(a.begin(),a.end(),nums2[i]);

            int diff=INT_MAX;

            if(it!=a.end())
                diff=min(diff,abs(nums2[i]-*it));

            if(it!=a.begin()){
                it--;
                diff=min(diff,abs(nums2[i]-*it));
            }

            int ans=prev-diff;
            mx=max(mx,(long long)ans);
        }

        return (sum-mx)%MOD;
    }
};