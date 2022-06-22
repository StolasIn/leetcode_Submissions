// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        for(int i=1;;i++){
            if(((i+1)*(i))/2==n) return i;
            if(((i+1)*(i))/2>n){
                return i-1;
            }
        }
        return 0;
    }
};