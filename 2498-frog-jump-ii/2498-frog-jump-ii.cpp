class Solution {
public:
    int maxJump(vector<int>& arr) {
        int jump=arr[1]-arr[0];
        int n=arr.size();
        for(int i=2;i<n;i++){
            jump=max(jump,arr[i]-arr[i-2]);
        }
        return jump;
    }
};