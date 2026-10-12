class Solution {
public:
    bool judgeSquareSum(int c) {
        int l=0,r=sqrt(c);
        while(l<=r){
            long long nm=1LL*l*l+1LL*r*r;
            if(nm==c)return true;
            else if(nm>c){
                r--;
            }else{
                l++;
            }
        }
        return false;
    }
};