class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int cnt1=0,cnt2=0,swap=0;
        int MOD=1e9+7;
        for(int x:nums){
            if(x<a){
                swap=(swap+cnt1+cnt2)%MOD;
            }
            else if(x<=b){
                swap=(swap+cnt2)%MOD;
                cnt1++;
            }else{
                cnt2++;
            }
        }
        return swap;
    }
};