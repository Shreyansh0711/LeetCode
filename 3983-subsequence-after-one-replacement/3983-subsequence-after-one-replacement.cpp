class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n>m)return false;
        if(n==1)return true;

        vector<int>l(n,1e9);
        vector<int>r(n,-1e9);
        int j=0;
        for(int i=0;i<n;i++){
            while(j<m&&t[j]!=s[i])j++;
            if(j<m){
                l[i]=j;
                j++;
            }else{
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            while(j>=0&&t[j]!=s[i])j--;
            if(j>=0){
                r[i]=j;
                j--;
            }else{
                break;
            }
        }

        if(r[1]>=1)return true;

        if(l[n-2]<=m-2)return true;

        for(int i=1;i<n-1;i++){
            if(r[i+1]-l[i-1]>=2){
                return true;
            }
        }
        return false;
    }
};