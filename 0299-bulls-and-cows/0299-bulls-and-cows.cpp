class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int>mp;
        int n=guess.size();
        vector<bool>vis(n,true);
        for(char c:guess){
            mp[c]++;
        }
        string ans="";
        int mth=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                mth++;
                mp[guess[i]]--;
                vis[i]=false;
            }
        }
        string crr=to_string(mth);
        ans+=crr+"A";
        int mth2=0;
        for(int i=0;i<n;i++){
            if(mp[secret[i]]>0&&vis[i]){
                mth2++;
                mp[secret[i]]--;
            }
        }
        string curr1=to_string(mth2);
        ans+=curr1+"B";
        return ans;
    }
};