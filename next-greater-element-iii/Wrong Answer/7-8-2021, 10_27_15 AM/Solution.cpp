// https://leetcode.com/problems/next-greater-element-iii

class Solution {
public:
    int nextGreaterElement(int n) {
        int arr[20];
        int cnt=0;
        while(n!=0){
            arr[cnt++]=n%10;
            n/=10;
        }
        //next_permutation(arr,arr+cnt-1);
        int ans=0;
        int pro=1;
        for(int i=cnt-1;i>=0;i--){
            ans+=arr[i]*pro;
            pro*=10;
        }
        if(ans<=n) return -1;
        return ans;
    }
};