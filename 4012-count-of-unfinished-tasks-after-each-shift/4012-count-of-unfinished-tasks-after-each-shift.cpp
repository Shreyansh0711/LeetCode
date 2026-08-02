class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        vector<int>ans;
        int n=tasks.size();
        vector<long long >pre(n);
        pre[0]=tasks[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+tasks[i];
        }

        long long tot=0;
        for(int i:shifts){
            tot+=i;
            if(tot>=pre.back()){
                ans.push_back(0);
                tot=0;
                continue;
            }
            int comp=upper_bound(pre.begin(),pre.end(),tot)-pre.begin();
            ans.push_back(n-comp);
        }
        return ans;
    }
};