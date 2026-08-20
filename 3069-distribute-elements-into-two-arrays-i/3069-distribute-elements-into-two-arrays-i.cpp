class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>v1;
        vector<int>v2;
        int n=nums.size();
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        int i=2;
        while(i<n){
            if(v1[v1.size()-1]>v2[v2.size()-1]){
                v1.push_back(nums[i]);
            }else{
                v2.push_back(nums[i]);
            }
            i++;
        }
        vector<int>ans;
        for(int x:v1){
            ans.push_back(x);
        }
        for(int x:v2){
            ans.push_back(x);
        }
        return ans;
    }
};