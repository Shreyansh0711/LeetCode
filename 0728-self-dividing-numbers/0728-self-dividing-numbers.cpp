class Solution {
public:
    bool self(int num){
        vector<int>nm;
        int tmp=num;
        while(num>0){
            nm.push_back(num%10);
            num/=10;
        }
        for(int x:nm){
            if(x==0||tmp%x!=0)return false;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int l, int r) {
        vector<int>ans;
        for(int i=l;i<=r;i++){
            if(self(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};