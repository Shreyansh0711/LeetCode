class Solution {
public:
    string rev(string &s1){
        string a="";
        for(int i=s1.size()-1;i>=0;i--){
            if(s1[i]=='1')a+='0';
            else a+='1';
        }
        return a;
    }
    char findKthBit(int n, int k) {
        vector<string>s(n,"0");
        if(n==1)return '0';
        
        for(int i=1;i<n;i++){
            s[i]=s[i-1]+'1'+rev(s[i-1]);
        }
        string ans=s[n-1];
        for(int i=0;i<ans.size();i++){
            if(i==k-1)return ans[i];
        }
        return '0';
    }
};