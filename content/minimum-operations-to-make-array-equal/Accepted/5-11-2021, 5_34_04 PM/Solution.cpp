// https://leetcode.com/problems/minimum-operations-to-make-array-equal

class Solution {
public:
    int minOperations(int n) {
        int arr[n];
        int sum=0;
        for(int i=0;i<n;i++){
            arr[i]=2*i+1;
            sum+=arr[i];
        }
        sum/=n;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(arr[i]-sum);
        }
        return ans/2;
    }
};