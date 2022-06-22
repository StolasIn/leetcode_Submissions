// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int m = nums.size();
        int l=0,r=m-1;
        int mid=0;
        int f=-1,e=-1;
        while(r>=l){
            mid=(r-l)/2+l;
            if(nums[mid]>target){
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                if(mid==0 || nums[mid-1]!=target){
                    f=mid;
                    break;
                }
                else{
                    r=mid-1;
                }
            }
        }
        l=0;
        r=m-1;
        while(r>=l){
            mid=(r-l)/2+l;
            if(nums[mid]>target){
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                if(mid==nums.size()-1 || nums[mid+1]!=target){
                    e=mid;
                    break;
                }
                else{
                    l=mid+1;
                }
            }
        }
        return {f,e};
    }
};