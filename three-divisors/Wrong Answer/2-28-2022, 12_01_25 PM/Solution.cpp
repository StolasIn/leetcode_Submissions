// https://leetcode.com/problems/three-divisors

class Solution {
public:
    bool isThree(int n) {
        if(fabs(sqrt(n) - (int)sqrt(n))>1e-6){
            return false;
        }
        n = sqrt(n);
        int m = sqrt(n); 
        for(int i=2;i<m+1;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
};