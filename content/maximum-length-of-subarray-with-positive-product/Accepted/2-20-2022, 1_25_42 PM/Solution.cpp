// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                pos++;
                if(neg!=0){
                    neg++;
                }
            }
            else if(nums[i]==0){
                pos = 0;
                neg = 0;
            }
            else{
                int t = neg;
                neg = pos + 1;
                if(t!=0){
                    pos = t + 1;
                }
                else{
                    pos = 0;
                }
            }
            ans = max(ans,pos);
        }
        return ans;
    }
};