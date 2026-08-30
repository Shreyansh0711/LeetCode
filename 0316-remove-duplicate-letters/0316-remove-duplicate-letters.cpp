class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>last(26,0);
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }
        vector<bool>seen(26,false);
        stack<char>st;
        for(int i=0;i<s.size();i++){
            int curr=s[i]-'a';
           if(seen[curr])continue;
            while(!st.empty()&&s[i]<st.top()&&i<last[st.top()-'a']){
                seen[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);
            seen[curr]=true;
        }
        string ans="";
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};