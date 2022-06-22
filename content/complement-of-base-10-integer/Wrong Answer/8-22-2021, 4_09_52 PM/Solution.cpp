// https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
public:
    int bitwiseComplement(int n) {
        int pro=1;
        while(pro<n){
            pro*=2;
        }
        return pro-n-1;
    }
};