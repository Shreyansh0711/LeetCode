class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        unordered_set<int>mp1;
        unordered_set<int>mp2;
        for(int i=0;i<n;i++){
            if(i==0||nums[i]!=nums[i-1]){
                if(mp1.count(nums[i])){
                    mp2.erase(nums[i]);
                }else{
                    mp1.insert(nums[i]);
                    mp2.insert(nums[i]);
                }
            }
        }
        return mp2.size();
    }
};