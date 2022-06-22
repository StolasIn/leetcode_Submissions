// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=1;
        vector<int> t;
        t.push_back(nums[0]);
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){ 
                cnt++;
                t.push_back(nums[i+1]);
            }
        }
        nums.clear();
        nums={t.begin(),t.end()};
        return cnt;
    }
};