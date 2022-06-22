// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int beg = -1;
        int neg = 0;
        int odd = 0;
        int even = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                neg++;
                swap(odd,even);
            }
            else if(nums[i]==0){
                beg = i;
                neg = 0;
            }
            if(neg%2==0){
                even = i - beg;
            }
            else{
                odd = i - beg;
            }
            ans = max(ans,even);
        }
        return ans;
    }
};