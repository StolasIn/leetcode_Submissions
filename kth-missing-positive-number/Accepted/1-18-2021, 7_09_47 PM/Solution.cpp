// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> ans(2020,0);
        for(int i=0;i<arr.size();i++){
            ans[arr[i]]=1;
        }
        for(int i=1;i<2020;i++){
            if(ans[i]==0) k--;
            if(k==0) return i;
        }
        return 0;
    }
};