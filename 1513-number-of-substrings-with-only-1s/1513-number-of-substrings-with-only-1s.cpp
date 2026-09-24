class Solution {
public:
    int numSub(string s) {
        int mod=1e9+7;
        int n=s.size();
        int len=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')len++;
            else len=0;
            ans=(ans+len)%mod;
        }
        return ans;
    }
};