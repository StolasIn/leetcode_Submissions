// https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        int count = 0;
        for(int i=0; i+m<n; i++)
        {
            if(arr[i]!=arr[i+m])
                count=0;
            count+=(arr[i]==arr[i+m]);
            if(count==(k-1)*m)
                return true;
        }
        return false;
    }
};