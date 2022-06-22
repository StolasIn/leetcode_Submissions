// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int ans;
    int partition1(vector<int> &arr,int left,int right){
        int pivot_index=rand()%(right-left+1)+left;
        int pivot=arr[pivot_index];
        swap(arr[pivot_index],arr[right]);
        int front1=left;
        for(int cur=left;cur<=right;cur++){
            if(arr[cur]>pivot){
                swap(arr[cur],arr[front1]);
                front1++;
            }
        }
        swap(arr[front1],arr[right]);
        return front1;
    }
    void quick_select(vector<int>& nums,int left,int right,int k){
        if(left==right) {ans=nums[left]; return;}
        if(right>left){
            int pivot=partition1(nums,left,right);
            if(k==pivot){
                ans=nums[pivot];
                return;
            }
            if(k>pivot){
                quick_select(nums,pivot+1,right,k);
            }
            else if(k<pivot){
                quick_select(nums,left,pivot-1,k);
            }
        }
    }
    int thirdMax(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        quick_select(nums,0,nums.size()-1,2);
        return ans;
    }
};