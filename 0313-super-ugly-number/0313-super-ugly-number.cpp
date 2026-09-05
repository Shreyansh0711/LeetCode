class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==1)return 1;
        int nm=primes.size();
        vector<int>idx(nm,0);
        int ug[n];
        ug[0]=1;
        for(int i=1;i<n;i++){
            long long mini=LLONG_MAX;
            for(int j=0;j<nm;j++){
                mini=min(mini,1LL*primes[j]*ug[idx[j]]);
            }
            ug[i]=(int)mini;
            for(int j=0;j<nm;j++){
                if(mini==1LL*primes[j]*ug[idx[j]]){
                    idx[j]++;
                }
            }
        }
        return ug[n-1];
    }
};