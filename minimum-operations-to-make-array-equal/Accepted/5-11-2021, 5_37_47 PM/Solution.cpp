// https://leetcode.com/problems/minimum-operations-to-make-array-equal

class Solution {
public:
    int minOperations(int n) {
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i]=2*i+1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(arr[i]-n);
        }
        return ans/2;
    }
};