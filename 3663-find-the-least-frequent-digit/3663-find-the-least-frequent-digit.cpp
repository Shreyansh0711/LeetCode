class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<char,int>mp;
        string s=to_string(n);
        for(char c:s){
            mp[c]++;
        }
        sort(s.begin(),s.end());
        int mini=INT_MAX;
        int num=-1;
        for(char c:s){
            if(mp[c]<mini){
                mini=mp[c];
                num=c-'0';
            }
        }
        return num;
    }
};