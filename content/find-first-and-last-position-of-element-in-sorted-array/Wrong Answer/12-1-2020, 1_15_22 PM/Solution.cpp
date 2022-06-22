// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return vector<int> {-1,-1};
        if(nums.size()==1 && nums[0]==target) return vector<int> {0,0};
        else if(nums.size()==1 && nums[0]!=target) return vector<int> {-1,-1};
        
        int n = nums.size();
        int l=0;
        int r=n-1;
        int m;
        int m1=-1;
        while(r>l){
            m=(l+r+1)/2;
            if(target>nums[m]){
                l=m+1;
            }
            else if(target<nums[m]){
                r=m-1;
            }
            else{
                m1=m;
                for(;m1>0 && nums[m1-1]==target;) m1--;
                for(;m<n-1 && nums[m+1]==target;) m++;
                break;
            }
        }
        if(m1==-1) return vector<int> {-1,-1};
        else return vector<int> {m1,m};
    }
};