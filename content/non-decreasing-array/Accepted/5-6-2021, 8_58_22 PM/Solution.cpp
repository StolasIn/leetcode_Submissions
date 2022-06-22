// https://leetcode.com/problems/non-decreasing-array

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0,tmp=-1;
        int m=nums.size();
        for(int i=1;i<m;i++){
            if(nums[i]<nums[i-1]){
                cnt++;
                tmp=i;
            }
        }
        //cout<<tmp<<endl;
        if(cnt>=2) return false;
        if(cnt==0) return true;
        if(tmp==m-1){
            return true;
        }
        else{
            if(nums[tmp-1]>nums[tmp+1]){
                nums[tmp-1]=nums[tmp];
            }
            else{
                nums[tmp]=(nums[tmp-1]+nums[tmp+1])/2;
            }
            cnt=0;
            for(int i=1;i<m;i++){
                if(nums[i]<nums[i-1]){
                    cnt++;
                    tmp=i;
                }
            }
            if(cnt==1) return false;
            return true;
        }
    }
};