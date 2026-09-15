class Solution {
public:
    bool pal(string &s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;r--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int ans=0;
        int i=0;
        int n=s.size();
        while(i+k<=n){
            bool find=false;
            if(pal(s,i,i+k-1)){
                ans++;
                i+=k;
            }else if(pal(s,i,i+k)){
                ans++;
                i+=k+1;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};