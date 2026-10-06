class Solution {
public:
    int minAddToMakeValid(string s) {
        int op=0,ans=0;
        for(char c:s){
            if(c=='(')op++;
            else{
                if(op>0)op--;
                else ans++;
            }
        }
        return ans+op;
    }
};