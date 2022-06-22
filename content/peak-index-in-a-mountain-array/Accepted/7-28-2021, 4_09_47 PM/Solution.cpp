// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int m=arr.size();
        int l=0,r=m-1;
        int mid;
        while(r>l){
            mid=(r+l)/2;
            if(mid==0 || mid==m){
                return mid;
            }
            else if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else{
                if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]){
                    l=mid;
                }
                else if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1]){
                    r=mid;
                }
                else{
                    if(mid>m/2){
                        l=mid;
                    }
                    else{
                        r=mid;
                    }
                }
            }
        }
        return -1;
    }
};