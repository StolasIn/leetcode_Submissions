// https://leetcode.com/problems/previous-permutation-with-one-swap

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int r=0;
        for(r=arr.size()-2;r>=0;r--){
            if(arr[r]>arr[r+1]){
                break;
            }
        }
        if(r==-1)
        {
            return arr;
        }
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]<arr[r]){
                while(i>=0 && arr[i-1]==arr[i]){
                    i--;
                }
                swap(arr[i],arr[r]);
                return arr;
            }
        }
        return arr;
    }
};