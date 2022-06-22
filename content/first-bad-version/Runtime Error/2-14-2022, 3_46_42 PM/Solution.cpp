// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while(right>=left){
            int mid = (right+left) / 2;
            if(isBadVersion(mid)==true){
                if(isBadVersion(mid-1)==false){
                    return mid;
                }
                else{
                    right = mid-1;
                }
            }
            else{
                left = mid+1;
            }
        }
        return -1;
    }
};