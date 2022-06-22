// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int m = nums.size();
        int l=0,r=m-1;
        int mid=0;
        int f=-1,e=-1;
        while(r>l){
            mid=(l+r)/2;
            if(nums[mid]>target){
                r=mid;
            }
            else if(nums[mid]<target){
                l=mid;
            }
            else{
                if(mid==0 || nums[mid-1]!=target){
                    f=mid;
                    break;
                }
                else{
                    r=mid;
                }
            }
        }
        l=0;
        r=m-1;
        while(r>l){
            mid=(l+r)/2;
            if(nums[mid]>target){
                r=mid;
            }
            else if(nums[mid]<target){
                l=mid;
            }
            else{
                if(mid==nums.size()-1 || nums[mid+1]!=target){
                    e=mid;
                    break;
                }
                else{
                    l=mid;
                }
            }
        }
        return {f,e};
    }
};