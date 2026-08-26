class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0, mini = INT_MAX;
        int one=0;
        string ans = "";
        for (int r = 0; r < s.size(); r++) {
            if (s[r] == '1') {
                one++;
            }
            while (one>k) {
                if (s[l] == '1') {
                    one--;
                }
                l++;
            }
            if (one==k) {
                while(l<r&&s[l]=='0')l++;
                int len=r-l+1;
                if(len<mini){
                    mini=len;
                    ans=s.substr(l,len);
                }
                else if(len==mini){
                    ans=min(ans,s.substr(l,len));
                }
            }
        }
        return ans;
    } 
};