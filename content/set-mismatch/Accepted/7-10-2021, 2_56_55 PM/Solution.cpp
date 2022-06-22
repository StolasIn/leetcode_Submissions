// https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int m=nums.size();
        int arr[m+1];
        int a,b=0;
        memset(arr,0,sizeof(arr));
        for(int i=0;i<m;i++){
            arr[nums[i]]++;
            if(arr[nums[i]]==2){
                a=nums[i];
            }
            b+=nums[i];
        }
        return {a,a+(m*(m+1)/2)-b};
    }
};