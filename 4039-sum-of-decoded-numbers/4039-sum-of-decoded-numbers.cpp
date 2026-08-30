class Solution {
public:
    long long power(long long b,long long e,long long mod){
        long long res=1;
        b%=mod;
        while(e>0){
            if(e&1)res=res*b%mod;
            b=b*b%mod;
            e>>=1;
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        const long long MOD=1e9+7;
        int n=nums.size();
        long long res=0;
        for(int i=0;i<n;i++){
            int w=nums[i]%10;
            long long k=nums[i]/10;
            string curr=to_string(k);
            long long x=stoll(curr.substr(0,w));
            long long y=stoll(curr.substr(w));
            long long ans=power(x,y,MOD);
            res=(res+ans)%MOD;
        }
        return res;
    }
};