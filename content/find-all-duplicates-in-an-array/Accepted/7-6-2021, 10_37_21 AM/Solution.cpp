// https://leetcode.com/problems/find-all-duplicates-in-an-array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int m=nums.size();
        int t;
        for(int i=0;i<m;i++){
            t=abs(nums[i])-1;
            if(nums[t]<0){
                ans.emplace_back(abs(nums[i]));
            }
            else{
                nums[t]=-nums[t];
            }
        }
        return ans;
	}
};