// https://leetcode.com/problems/wiggle-sort-ii

class Solution {
public:
    void counting(vector<int>& nums){
        vector<int> bu(5000,0);
        int m=nums.size();
        for(int i=0;i<m;i++){
            bu[nums[i]]++;
        }
        nums.clear();
        int l=0,r=4999;
        for(int i=0;i<5000;i++){
            if(bu[i]!=0)
                for(int j=0;j<bu[i];j++)
                    nums.emplace_back(i);
        }
    }
    void wiggleSort(vector<int>& nums) {
        counting(nums);
        int m=nums.size();
        vector<int> tmp(m);
        int cnt=0;
        for(int i=0;i<m;i+=2){
            tmp[i]=nums[cnt++];
        }
        for(int i=1;i<m;i+=2){
            tmp[i]=nums[cnt++];
        }
        nums.assign(tmp.begin(),tmp.end());
    }
};