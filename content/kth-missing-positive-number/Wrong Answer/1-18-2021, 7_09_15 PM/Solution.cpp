// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> ans(1010,0);
        int max1=-INT_MAX;
        for(int i=0;i<arr.size();i++){
            ans[arr[i]]=1;
            max1=max(max1,arr[i]);
        }
        for(int i=1;i<1010;i++){
            if(ans[i]==0) k--;
            if(k==0) return i;
        }
        return 0;
    }
};