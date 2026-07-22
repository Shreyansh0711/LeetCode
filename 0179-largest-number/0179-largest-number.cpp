class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>a;
        for(int num:nums){
            a.push_back(to_string(num));
        }

        sort(a.begin(),a.end(),[](const string &a,const string &b){
            return (b+a)<(a+b);
        });

        if(a[0]=="0") return "0";

        string largest;
        for(const string &num:a){
            largest+=num;
        }
        return largest;
    }  
};