class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        string ans;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(ans.size());
            }
            else if(s[i]==')'){
                int tp=st.top();
                st.pop();
                reverse(ans.begin()+tp,ans.end());
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};