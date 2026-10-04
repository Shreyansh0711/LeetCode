class Solution {
public:
    int minopr(int a,int b){
        int d=abs(a-b);
        return min(d,10-d);
    }
    int minRotations(int n, string s) {
        
        int curr=0;
        int ans=0;
        for(char c:s){
            int x=c-'0';
            int d=abs(x-curr);
            ans+=min(d,10-d);
            curr=x;
        }
        int res=ans;
        for(int k=0;k<n;k++){
            int prev=(k==0?0:s[k-1]-'0');
            int cur=s[k]-'0';
            int lst=s[n-1]-'0';
            int cost=ans-minopr(prev,cur)+minopr(prev,lst);
            res=min(res,cost);
        }
        return res;
    }
};