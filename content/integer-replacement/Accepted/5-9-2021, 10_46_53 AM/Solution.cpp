// https://leetcode.com/problems/integer-replacement

class Solution {
public:
    int re(int n){
        if(n==1) return 0;
        if(n%2==0){
            n/=2;
            return re(n)+1;
        }
        else{
            if(n==INT_MAX) return re(n-1);
            return min(re(n-1),re(n+1))+1;
        }
    }
    int integerReplacement(int n) {
        return re(n);
    }
};