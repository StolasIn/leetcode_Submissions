// https://leetcode.com/problems/calculate-money-in-leetcode-bank

class Solution {
public:
    int cal(int b,int n){
        return ((b+(b+n-1)) * n) / 2;
    }
    int totalMoney(int n) {
        int b = 1;
        int ans = 0;
        while(n!=0){
            if(n>7){
                ans+=cal(b,7);
                n-=7;
            }
            else{
                ans+=cal(b,n);
                n=0;
            }
            b++;
        }
        return ans;
    }
};