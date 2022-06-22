// https://leetcode.com/problems/kth-largest-element-in-an-array

#define swap(x,y) int tmp=x; x=y; y=tmp;
class Solution {
public:
    //找出pivot
    int ans;
    int partition1(vector<int> &arr,int left,int right){
        int pivot=arr[right]; //令陣列的最後一個元素是pivot
        int front1=left-1; //front1用來交換元素
        for(int cur=left;cur<right;cur++){ //cur枚舉陣列的所有元素
            if(arr[cur]<pivot){ //如果當前的元素比pivot小，就擺到左邊
                front1++; //替換的位置加1
                swap(arr[cur],arr[front1]); //互換
            }
        }
        //把pivot換到目前陣列front1+1的位置，就可以確保在pivot左邊的元素都比pivot小
        front1++; //front1+1的位置
        swap(arr[front1],arr[right]);
        return front1;//把pivot回傳
    }
    void quick_select(vector<int>& nums,int left,int right,int k){
        if(right>left){
            int pivot=partition1(nums,left,right);
            if(right-k==pivot-1){
                ans=nums[pivot];
            }
            /*for(int i=0;i<nums.size();i++){
                cout<<nums[i]<<" ";
            }*/
            if(right-k>pivot-1){
                quick_select(nums,pivot+1,right,k);
            }
            else{
                quick_select(nums,left,pivot-1,k);
            }
            //quick_select(nums,pivot+1,right,k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0];
        quick_select(nums,0,nums.size(),k);
        return ans;
    }
};