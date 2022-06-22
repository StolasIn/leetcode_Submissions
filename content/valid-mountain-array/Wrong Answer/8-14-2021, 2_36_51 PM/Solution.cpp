// https://leetcode.com/problems/valid-mountain-array

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int cnt=0;
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
                cnt++;
            }
            if(arr[i-1]==arr[i] || arr[i]==arr[i+1]){
                return false;
            }
        }
        return cnt==1;
    }
};