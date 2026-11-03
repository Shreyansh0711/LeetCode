class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> prem(n), arr(n);
        for(int i=0;i<n;i++) prem[i]=i;

        int cnt=0;

        do {
            for(int i=0;i<n;i++){
                if(i&1) arr[i]=prem[n/2+(i-1)/2];
                else arr[i]=prem[i/2];
            }

            prem=arr;
            cnt++;

        } while(prem[0]!=0 || prem[1]!=1);

        return cnt;
    }
};