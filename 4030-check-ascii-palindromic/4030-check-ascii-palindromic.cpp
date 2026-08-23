class Solution {
public:
    bool isPalindromic(string s) {
        
        string ans="";
        for(char c:s){
            int num=(int)c;
            string curr="";
            for(int i=7;i>=0;i--){
                curr+=((num>>i)&1)+'0';
            }
            ans+=curr;
        }
        int l=0,r=ans.size()-1;
        while(l<r){
            if(ans[l]!=ans[r])return false;
            l++;
            r--;
        }
        return true;
    }
};