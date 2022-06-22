// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt=0;
        int i;
        for(i=1;cnt<arr.size();i++){
            if(i==arr[cnt]){
                cnt++;
            }
            else{
                k--;
            }
            if(k==0) return i;
        }
        return i+k-1;
    }
};