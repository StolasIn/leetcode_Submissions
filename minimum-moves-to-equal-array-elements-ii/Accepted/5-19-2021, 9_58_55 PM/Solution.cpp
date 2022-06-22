// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

class Solution {
public:
    //找出pivot
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
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0];
        quick_select(nums,0,nums.size()-1,k-1);
        return ans;
    }
    int minMoves2(vector<int>& nums) {
        int m=nums.size();
        double best;
        int ans;
        
        if(m%2==0){
            ans=(findKthLargest(nums,m/2)+findKthLargest(nums,m/2+1))/2;
            /*if(best-floor(best)>0.5){
                ans=(int)(best)+1;
            }
            else{
                ans=(int)(best);
            }*/
        }
        else{
            ans=findKthLargest(nums,m/2+1);
        }
        //cout<<ans<<endl;
        int sum=0;
        for(int i=0;i<m;i++){
            sum+=abs(nums[i]-ans);
        }
        return sum;
    }
};