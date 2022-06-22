// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int t,ans=0;
        for(int i=0;i<nums.size();i++){
            t=0;
            while(nums[i]!=0){
                t++;
                nums[i]/=10;
            }
            if(t%2==0){
                ans++;
            }
        }
        return ans;
    }
};