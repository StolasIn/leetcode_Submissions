// https://leetcode.com/problems/mean-of-array-after-removing-some-elements

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int m = arr.size();
        int skip = m / 20;
        int ans = 0;
        nth_element(arr.begin(), arr.begin() + skip, arr.end());
        nth_element(arr.begin() + skip, arr.begin() + m - skip, arr.end());
        for(int i=skip;i<m-skip;i++){
            ans+=arr[i];
        }
        return ans / (m-2*skip);
    }
};