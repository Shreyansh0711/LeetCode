class Solution {
public:
    int minRotations(string s) {
        int curr=0;
        int ans=0;
        for(char c:s){
            int x=c-'0';
            int d=abs(curr-x);
            ans+=min(10-d,d);
            curr=x;
        }
        return ans;
    }
};