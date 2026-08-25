class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        
        map<int,int>mp;
        for(int x:nums)mp[x]++;
        for(int i=k;i<=k*n;i+=k){
            if(mp[i]==0){
                return i;
            }
        }
        return k*(n+1);
    }
};