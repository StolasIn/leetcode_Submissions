// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1;
        int r=n;
        int mid;
        int ans;
        while(r>=l){
            mid=(l+r)/2;
            if(isBadVersion(mid)==true){
                //if(isBadVersion(mid-1)==false) return mid;
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        cout<<endl;
        return ans;
    }
};