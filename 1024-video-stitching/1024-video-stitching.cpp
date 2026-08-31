class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int curr=0,i=0,ans=0,far=0;
        while(curr<time){
            while(i<clips.size()&&clips[i][0]<=curr){
                far=max(far,clips[i][1]);
                i++;
            }
            if(curr==far)return -1;
            curr=far;
            ans++;
        }
        return ans;
    }
};