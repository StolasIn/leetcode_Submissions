// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return vector<int> {-1,-1};
        int n = nums.size();
        int l=0;
        int r=n-1;
        int m;
        int m1=-1;
        while(r>l){
            m=(l+r)/2;
            if(target>nums[m]){
                l=m+1;
            }
            else if(target<nums[m]){
                r=m-1;
            }
            else{
                m1=m;
                for(;m1>=0;m1--){
                    if(nums[m1]!=target) break;
                }
                for(;m<n;m++){
                    if(nums[m]!=target) break;
                }
                break;
            }
        }
        if(m1==-1) return vector<int> {-1,-1};
        else return vector<int> {m1+1,m-1};
    }
};