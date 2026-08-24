class Solution {
public:
    vector<int>f(int x){
        vector<int>res;

        for(int i=2;i*i<=x;i++){
            if(x%i==0)res.push_back(i);
            while(x%i==0){
                x/=i;
            }
        }
        if(x>1)res.push_back(x);
        return res;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int l=0,ans=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int r=0;r<n;r++){
            for(int p:f(nums[r])){
                mp[p]++;
            }
            while(mp.size()>k){
                for(int p:f(nums[l])){
                    mp[p]--;
                    if(mp[p]==0)mp.erase(p);
                }
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};