// https://leetcode.com/problems/perfect-number

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1) return false;
        int sq=((int)sqrt(num))+1;
        int ans=0;
        for(int i=2;i<sq;i++){
            if(num%i==0){
                ans+=i;
                ans+=num/i;
            }
        }
        ans++;
        return num==ans;
    }
};