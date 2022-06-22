// https://leetcode.com/problems/k-concatenation-maximum-sum

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int now=0;
        int ma=-INT_MAX;
        for(int i=0;i<k;i++){
            for(int j=0;j<arr.size();j++){
                if(now<0){
                    now=0;
                }
                now+=arr[j];
                ma=max(ma,now);
            }
        }
        return ma;
    }
};