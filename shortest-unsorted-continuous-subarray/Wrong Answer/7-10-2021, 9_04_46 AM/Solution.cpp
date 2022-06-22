// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int m=nums.size();
        //vector<int> v;
        int l=0,r=0;
        for(int i=1;i<m;i++){
            if(nums[i]<nums[i-1]){
                l=min(l,i-1);
                r=max(r,i);
            }
        }
        /*for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;*/
        return r-l;
    }
};