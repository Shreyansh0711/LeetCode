class Solution {
public:
    bool checkDivisibility(int n) {
        int sm=0,pro=1;
        int temp=n;
        while(temp>0){
            sm+=temp%10;
            pro*=temp%10;
            temp/=10;
        }
        if(n%(sm+pro)==0)return true;
        return false;
    }
};