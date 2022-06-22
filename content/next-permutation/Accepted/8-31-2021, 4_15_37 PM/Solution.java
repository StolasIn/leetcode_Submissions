// https://leetcode.com/problems/next-permutation

class Solution {
    public void swap(int[] arr,int i,int j){
        int tmp = arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
    }
    public void reverse(int[] arr,int i,int j){
        j--;
        while(j>i){
            swap(arr,i,j);
            i++;
            j--;
        }
    }
    public void nextPermutation(int[] nums) {
        int r=nums.length-2;
        int mi=Integer.MAX_VALUE,pos=0;
        int tmp;
        for(;r>=0;r--){
            if(nums[r+1]>nums[r]){
                break;
            }
        }
        if(r==-1){
            reverse(nums,0,nums.length);
            return;
        }
        for(int i=nums.length-1;i>r;i--){
            if(nums[i]>nums[r]){
                pos=i;
                break;
            }
        }
        swap(nums,r,pos);
        reverse(nums,r+1,nums.length);
    }
}