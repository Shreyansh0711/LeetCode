class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string>mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        int i=0;
        string ans="";
        while(i<s.size()){
            if(s[i]=='('){
                int j=i+1;
                string curr="";
                while(j<s.size()&&s[j]!=')'){
                    curr+=s[j];
                    j++;
                }
                if(mp.find(curr)!=mp.end()){
                    ans+=mp[curr];
                }else{
                    ans+='?';
                }
                i=j+1;
                continue;
            }
            ans+=s[i];
            i++;
        }
        return ans;
    }
};