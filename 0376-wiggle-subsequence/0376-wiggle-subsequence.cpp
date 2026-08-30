class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <2)
            return n;
        int prev=nums[1]-nums[0];
        int ans=(prev!=0)?2:1;

        for(int i=2;i<n;i++){
            int diff=nums[i]-nums[i-1];

            if((diff>0&&prev<=0||(diff<0&&prev>=0))){
                ans++;
                prev=diff;
            }
        }
        return ans;
    }
};