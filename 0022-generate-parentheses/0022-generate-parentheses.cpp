class Solution {
public:
    void find(int o,int c,string s,int n,vector<string>&ans){
        if(o==c&&o+c==2*n){
            ans.push_back(s);
            return ;
        }
        if(o<n){
            find(o+1,c,s+'(',n,ans);
        }
        if(o>c){
            find(o,c+1,s+')',n,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        find(0,0,"",n,ans);
        return ans;
    }
};