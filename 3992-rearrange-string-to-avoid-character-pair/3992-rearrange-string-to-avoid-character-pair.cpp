class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]==y)ans+=s[i];
        }
        for(int i=0;i<s.size();i++){
            if(s[i]==y)continue;
            ans+=s[i];
        }
        return ans;
    }
};