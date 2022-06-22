// https://leetcode.com/problems/degree-of-an-array

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.size()==1) return 1;
        unordered_map<int,int> map;
        int l=0,r=0;
        int ma=0;
        int tmp;
        for(auto& i : nums){
            map[i]++;
        }
        for(auto& i : map){
            if(ma<i.second){
                ma=i.second;
                tmp=i.first;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==tmp){
                l=i;
                break;
            }
        }
        for(int i=nums.size();i>=0;i--){
            if(nums[i]==tmp){
                r=i;
                break;
            }
        }
        return r-l+1;
    }
};