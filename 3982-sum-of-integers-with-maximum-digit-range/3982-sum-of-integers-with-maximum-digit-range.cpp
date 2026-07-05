class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxrange=-1;
        long long curr=0;

        for(int num:nums){
            string s=to_string(num);

            int maxi=*max_element(s.begin(),s.end())-'0';
            int mini=*min_element(s.begin(),s.end())-'0';

            int r=maxi-mini;

            if(r>maxrange){
                maxrange=r;
                curr=num;
            }else if(r==maxrange){
                curr+=num;
            }
        }
        return curr;
    }
};