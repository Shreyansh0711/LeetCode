class Solution {
public:
    long long countCommas(long long n) {
        string s=to_string(n);
        if(s.size()<4){
            return 0;
        }
        long long nm=0;
        for(int i=0;i<s.size();i++){
            nm=nm*10+(s[i]-'0');
        }
        long long k=1000;
        long long ans=0;
        while(k<=nm){
            ans+=nm-k+1;
            k*=1000;
        }
        return ans;
    }
};