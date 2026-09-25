class Solution {
public:
vector<vector<string>>ans;
vector<string>curr;
bool pal(string &s,int x,int y){
        while(x<y){
            if(s[x]!=s[y])return false;
            x++;y--;
        }
        return true;
    }
void solve(string &s,int i){
    if(i==s.size()){
        ans.push_back(curr);
        return;
    }
    for(int j=i;j<s.size();j++){
        if(pal(s,i,j)){
            curr.push_back(s.substr(i,j-i+1));
            solve(s,j+1);
            curr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
       solve(s,0);
       return ans;
    }
};