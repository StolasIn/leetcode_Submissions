// https://leetcode.com/problems/valid-mountain-array

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool flag=false;
        if(arr.size()<3) return false;
        if(arr[0]>arr[1]) return false;
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]>arr[i]){
                flag=true;
            }
            if(flag && arr[i-1]<arr[i]) return false;
            if(arr[i-1]==arr[i]){
                return false;
            }
        }
        if(flag==false) return false;
        return true;
    }
};