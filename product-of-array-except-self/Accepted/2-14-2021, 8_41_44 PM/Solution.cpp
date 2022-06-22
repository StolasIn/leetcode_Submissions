// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int m=nums.size();
        vector<int> left(m);
        vector<int> right(m);
        vector<int> ans(m);
        left[0]=right[m-1]=1;
        for(int i=1;i<m;i++){
            left[i]=nums[i-1]*left[i-1];
            right[m-i-1]=nums[m-i]*right[m-i];
        }
        for(int i=0;i<m;i++){
            ans[i]=left[i]*right[i];
        }
        return ans;
    }
};