class Solution {
public:
    int smallestNumber(int n, int t) {
        
        int num=1;
        while(true){
            int temp=n;
            int curr=1;
            while(temp>0){
                if(temp%10==0)return n;
                curr*=temp%10;
                temp/=10;
            }
            if(curr%t==0){
                return n;
                break;
            }else{
                n++;
            }
        }
        return 0;
    }
};