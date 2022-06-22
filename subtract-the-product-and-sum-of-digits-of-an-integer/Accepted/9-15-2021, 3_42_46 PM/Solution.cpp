// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0;
        int pro=1;
        int m;
        while(n!=0){
            m=n%10;
            sum+=m;
            pro*=m;
            n/=10;
        }
        return pro-sum;
    }
};