// https://leetcode.com/problems/sort-even-and-odd-indices-independently

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m = nums.size();
        vector<int> ans(m);
        int l = 0,r = m-1;
        for(int i=0;i<m;i++){
            if(nums[i]%2==0){
                ans[l] = nums[i];
                l+=2;
            }
            else{
                ans[r] = nums[i];
                r-=2;
            }
        }
        return ans;
    }
};