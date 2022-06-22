// https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements

class Solution {
public:
    int countElements(vector<int>& nums) {
        int mi = *min_element(nums.begin(),nums.end());
        int ma = *max_element(nums.begin(),nums.end());
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mi && nums[i]<ma){
                cnt++;
            }
        }
        return cnt;
    }
};