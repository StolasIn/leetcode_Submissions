// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        vector<int> ans;
        int l=0,r=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0){
                left.emplace_back(nums[i]);
            }
            else{
                right.emplace_back(nums[i]);
            }
        }
        reverse(left.begin(),left.end());
        while(l<left.size() || r<right.size()){
            if(l<left.size() && r<right.size()){
                if(left[l] * left[l] < right[r] * right[r]){
                    ans.emplace_back(left[l] * left[l]);
                    l++;
                }
                else{
                    ans.emplace_back(right[r] * right[r]);
                    r++;
                }
            }
            else if(l<left.size()){
                ans.emplace_back(left[l] * left[l]);
                l++;
            }
            else{
                ans.emplace_back(right[r] * right[r]);
                r++;
            }
        }
        return ans;
    }
};