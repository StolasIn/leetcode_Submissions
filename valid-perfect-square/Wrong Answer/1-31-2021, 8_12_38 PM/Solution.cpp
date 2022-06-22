// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return true;
        int left=1;
        int right=num/2;
        int mid,tmp;
        while(right>left){
            mid=(right+left)/2;
            tmp=mid*mid;
            if(tmp>num){
                right=mid-1;
            }
            else if(tmp<num){
                left=mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};