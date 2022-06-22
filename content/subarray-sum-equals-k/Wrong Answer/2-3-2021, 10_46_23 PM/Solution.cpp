// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n+1);
        int cnt=0;
        int tmp;
        for(int i=0,sum=0;i<n;i++){
            sum+=nums[i];
            pre[i+1]=sum;
        }
        pre[0]=0;
        int beg=0,end=1;
        while(beg!=n){
            tmp=pre[end]-pre[beg];
            if(tmp==k){
                cnt++;
                beg++;
            }
            else if(tmp>k && beg<end){
                beg++;
            }
            else if(tmp>k && beg>=end){
                end++;
                beg++;
            }
            else if(tmp<k && end!=n){
                end++;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};