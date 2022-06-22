// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l,r;
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans;
        if(nums.size()==0) return ans;
        if(nums.size()<3) return ans;
        for(int i=0;i<nums.size()-2;i++){
            l=i+1;
            r=nums.size()-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]>0){
                    r--;
                }
                else if(nums[i]+nums[l]+nums[r]<0){
                    l++;
                }
                else{
                    ans.push_back(vector<int>());
                    ans[ans.size()-1].push_back(nums[i]);
                    ans[ans.size()-1].push_back(nums[l]);
                    ans[ans.size()-1].push_back(nums[r]);
                    break;
                }
            }
        }
        return ans;
    }
};