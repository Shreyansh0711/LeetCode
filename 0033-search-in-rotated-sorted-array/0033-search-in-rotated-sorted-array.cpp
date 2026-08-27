class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(target>nums[nums.size()-1]){
            int id1=max_element(nums.begin(),nums.end())-nums.begin();
            int low=0;
            int high=id1;
            while(low<=high){
                int mid=(low+high)/2;
                if(nums[mid]==target){
                    return mid;
                }
                else if(nums[mid]>target)high=mid-1;
                else low=mid+1;
            }
        }else{
            int id2=min_element(nums.begin(),nums.end())-nums.begin();
            int l=id2;
            int h=nums.size()-1;
            while(l<=h){
                int m=(l+h)/2;
                if(nums[m]==target){
                    return m;
                }else if(nums[m]<target)l=m+1;
                else h=m-1;
            }
        }
        return -1;
    }
};