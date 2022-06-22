// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int m=nums.size();
        vector<int> pre(m+1,0);
        for(int i=1;i<=m;i++){
            pre[i]=nums[i-1]+pre[i-1];
        }
        pre.emplace_back(0);
        for(int i=1;i<=m;i++){
            if(pre[i-1]==pre[m]-pre[i]){
                return i-1;
            }
        }
        return -1;
    }
};