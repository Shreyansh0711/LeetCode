class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1)return x;
        int l=1;
        int h=x;
        while(l<=h){
            int mid=l+(h-l)/2;
            if((long)mid*mid>x){
                h=mid-1;
            }
            else if(mid*mid==x)return mid;
            else{
                l=mid+1;
            }
        }
        return static_cast<int>(std::round(h));
    }
};