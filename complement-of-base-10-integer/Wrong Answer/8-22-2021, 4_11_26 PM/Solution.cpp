// https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        else if(n==1) return 0;
        else if(n==2) return 1;
        int pro=1;
        while(pro<n){
            pro*=2;
        }
        return pro-n-1;
    }
};