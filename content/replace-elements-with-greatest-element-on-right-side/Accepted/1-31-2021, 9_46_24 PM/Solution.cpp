// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max1=-1;
        int m=arr.size();
        int tmp;
        for(int i=m-1;i>=0;i--){
            tmp=arr[i];
            arr[i]=max1;
            max1=max(tmp,max1);
        }
        return arr;
    }
};