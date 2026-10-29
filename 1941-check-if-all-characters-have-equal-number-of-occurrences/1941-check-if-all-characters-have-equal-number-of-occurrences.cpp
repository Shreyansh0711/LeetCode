class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        int eq=mp[s[0]];
        for(char c:s){
            if(mp[c]!=eq)return false;
        }
        return true;
    }
};