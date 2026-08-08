class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<string,int>mp;
        if (s.size() < 10)
            return ans;
        for(int i=0;i<=s.size()-10;i++){
            string curr=s.substr(i,10);
            mp[curr]++;
            if(mp[curr]==2){
                ans.push_back(curr);
            }
        }
        return ans;
    }
};