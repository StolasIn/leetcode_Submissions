// https://leetcode.com/problems/divide-array-into-equal-pairs

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int arr[501]={0};
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        for(int i=0;i<501;i++){
            if(arr[i]%2!=0){
                return false;
            }
        }
        return true;
    }
};