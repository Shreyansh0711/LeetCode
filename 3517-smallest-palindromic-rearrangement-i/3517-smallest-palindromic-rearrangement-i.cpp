class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int>a(26,0);
        for(int i=0;i<n/2;i++){
            a[s[i]-'a']++;
        }
        int l=0,r=n-1;
        for(int i=0;i<26;i++){
            while(a[i]>0){
                char c=i+'a';
                s[l++]=c;
                s[r--]=c;
                a[i]--;
            }
        }
        return s;
    }
};